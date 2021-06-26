import os
import sys
import subprocess
import pprint


def url_collections_get(_path = None):
    if _path is None:
        _path = os.getcwd() + "/"
    #cmd = 'grep -Rn \\"/redfish/v1 ' + _path + '*.json'
    cmd = 'grep -Rn \\"/redfish/v1 ' + _path + '/*.json|awk \'{print $2}\''
    #print(cmd)
    child = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
   # child.wait()
    return child.stdout.read()


def create_template_tree(path, url_collections):
    lines = url_collections.split("\n")
    uri_nodes = []

    for line in lines:
        line = line.strip()
        line = line.strip(",")
        line = line.strip("\"")
        
        nodes = line.split("/")
        if len(nodes) > 0:
            uri_nodes.append(nodes[1:])
        node_path = path
        for node in nodes[3:]:
            if len(node) == 0:
                continue
            if "{" in node:
                continue
            node_path = os.path.join(node_path, node)
#        print(path)
        cmd = 'mkdir -p ' + node_path
        child = subprocess.Popen(cmd, shell=True)

        node_path = path
        for node in nodes[3:]:
            if len(node) == 0:
                continue
            if "{" in node:
#                print(path)
                cmd = 'touch ' + node_path + "/id"
                child = subprocess.Popen(cmd, shell=True)
                continue
            node_path = os.path.join(node_path, node)
    return uri_nodes
#        print(nodes[3:])

def create_node_file(path, uri_list):
    method_list = {
        'get': 'HTTP_METHOD_GET',
        'post': 'HTTP_METHOD_POST', 
        'put': 'HTTP_METHOD_PUT',
        'patch': 'HTTP_METHOD_PATCH', 
        'delete': 'HTTP_METHOD_DELETE',
    }
    cfile = open(path, 'w')
    cfile.write("""
#include <stdio.h>
#include \"rest_node.h\"
#include \"http.h\"

""")

    for tp in uri_list:
        uri = tp[0]
        method = tp[1]
        node_start = uri.rfind("/")
        node_parent_start = None
        if "{id}" in uri[node_start + 1:]:
            node_parent_start = uri[:node_start].rfind("/")
        if node_parent_start is None:
            ff = uri[node_start + 1:].replace("-", "_")
        else:
            ff = uri[node_parent_start + 1:node_start].replace("-", "_") + "_id"
        ff = ff.replace("$", "")
        ff = ff.replace(".", "_")

        method_mask = "0"
        case = ""
        for m in method:
            if m in method_list.keys():
                if method_mask == "0":
                    method_mask = method_list[m]
                else:
                    method_mask += "|" + method_list[m]
                case += """
        case """ + method_list[m] + """:
            return 0;
"""
        cfile.write("""
static int rest_""" + ff.lower() + """_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\\n", __func__, __LINE__);

    switch(http_method_get(p)) {
""" + case + """
        default:
            return -1;
    }
}
""")
        cfile.write("\n")
        cfile.write("REST_BIND(\"" + uri + "\", " + method_mask + ", rest_" + ff.lower() + "_handler);")
        cfile.write("\n")
    cfile.close()

def create_rest_file(path, lv, uri_pattern):

    is_collection = False
    if lv == 1:
        uri_pattern_list = [
            ("/redfish", ['get']),
            ("/redfish/v1", ['get']),
            ("/redfish/v1/$metadata", ['get']),
            ("/redfish/v1/odata", ['get'])
        ]
        create_node_file(path + "/root.c", uri_pattern_list)
    else:
        create_node_file(path + "/node.c", [(uri_pattern, ['get'])])
        if os.path.exists(os.path.join(path, "id")):
            uri_pattern += "/{id}"
            create_node_file(path + "/node_id.c", [(uri_pattern, ['get'])])

    d = os.listdir(path)
    for f in d:
        cur_path = os.path.join(path, f)
        if os.path.isdir(cur_path):
            cur_uri_pattern = uri_pattern + "/" + f
            create_rest_file(cur_path, lv + 1, cur_uri_pattern)

def create_cmake(path):
    f = open(path + "/CMakeLists.txt", 'w')
    f.write("""
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

# Set up the project
project(redfish
    VERSION 1.0.0 
    LANGUAGES C
)

add_library(${PROJECT_NAME})
add_library("simple_redfish::${PROJECT_NAME}" ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    "simple_redfish::http"
    "simple_redfish::rest"
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}
)
""")
    f.write("aux_source_directory(${CMAKE_CURRENT_LIST_DIR} _SRC)\n")
    f.write("\n")

    list_dirs = os.walk(path)
    dir_list = []
    lv1_keys = []
    for root, dirs, files in list_dirs:
        for d in dirs:
            p = os.path.join(root, d)
            p = p[len(path):]
            dir_list.append(p)
            keys = p.split("/")
            if keys[1] not in lv1_keys:
                lv1_keys.append(keys[1])
    dir_list.sort()
#    print(lv1_keys)
    for key in lv1_keys:
        f.write("OPTION(" + key.upper() + " \"\" OFF)\n")

    f.write("\n")

    lv1_keys = []
    for d in dir_list:
        key = d.split("/")[1]
        if key not in lv1_keys:
            if len(lv1_keys) != 0:
                f.write("endif()\n\n")
            f.write("if(" + key.upper() + ")\n")
            lv1_keys.append(key)
        f.write("aux_source_directory(${CMAKE_CURRENT_LIST_DIR}" + d + " _SRC)\n")
    f.write("endif()\n\n")

    f.write('''
target_sources(${PROJECT_NAME}
    PRIVATE
    ${_SRC}
)
    ''')

    f.close()

import json

def collect_actions_from_js(schema_path, properties):
    actions = []
    for property_key, property_val in properties.items():
        if property_key[0] == '#':
#            print("==========="+schema_path)
#            print(property_key)
            if property_key not in actions:
                actions.append(property_key)
    return actions


def collection_member_items_ref_get(js):
    refs = []
    for k, v in js.items():
    #    print(k)
        if k == 'Members':
    #        print(v)
            refs.append(v['items']['$ref'])
        if type(v) == type({}):
            res = collection_member_items_ref_get(v)
            refs += res
        if type(v) == type([]):
            for vv in v:
                if type(vv) == type({}):
                    res = collection_member_items_ref_get(vv)
                    refs += res
    return refs


def ref_version_get(refs, name):
    v = []
    for ref in refs:
        if not name in ref['$ref']:
            continue
        uri = ref['$ref']
        start_pos = uri.find("/v1/") + len("/v1/")
        end_pos = uri.rfind("#")
        fname = uri[start_pos:end_pos]
        section = uri[end_pos + 1:].split("/")[2]
#        print(fname)
#        print(section)
        v.append(fname)
    return v

def collect_actions(schema_dir, template_dir):
    schemas = os.listdir(schema_dir)
    action_list = {}
    for schema in schemas:
        schema_path = os.path.join(schema_dir, schema)
        if not os.path.isfile(schema_path):
            continue
        if not 'Collection.json' in schema:
            continue
        #print(schema_path)
        with open(schema_path, 'r') as f:
            js = json.load(f)
            member_items_refs = collection_member_items_ref_get(js)
            #print(member_items_refs)
            f.close()
        for ref in member_items_refs:
            start_pos = ref.find("/v1/") + len("/v1/")
            end_pos = ref.rfind("#")
            fname = ref[start_pos:end_pos]
            section = ref[end_pos + 1:].split("/")[2]
            if section not in action_list.keys():
                action_list[section] = {
                    'uris':[],
                    'actions':[]
                }
#            print(fname)
#            print(section)
            ref_path = os.path.join(schema_dir, fname)
#            print(ref_path)
            uris = []
            with open(ref_path, 'r') as f_ref:
                js = json.load(f_ref)
                refs = js['definitions'][section]['anyOf']
                if 'uris' in js['definitions'][section]:
                    uris = js['definitions'][section]['uris']
                f_ref.close()
 #           print(refs)
#            print(uris)
            action_list[section]['uris'] += uris
            ref_vers = ref_version_get(refs, section)
#            print(ref_vers)
            for ref_ver in ref_vers:
                ref_ver_path = os.path.join(schema_dir, ref_ver)
                with open(ref_ver_path, 'r') as f_refver:
                    js = json.load(f_refver)
                    f_refver.close()
                if 'Actions' in js['definitions']:
                    properties = js['definitions']['Actions']['properties']
 #                   print(properties)
                    actions = collect_actions_from_js(schema_path, properties)
                    for action in actions:
                        if action not in action_list[section]['actions']:
                            action_list[section]['actions'].append(action)
    return action_list


def create_action_node(action_list, template_dir):
    for k, v in action_list.items():
        uris = v['uris']
        actions = v['actions']
        for uri in uris:
            dirs = uri.split("/")[3:]
            #print(dirs)
            path = template_dir
            pattern = "/redfish/v1"
            for dir in dirs:
                if "{" in dir:
                    pattern += "/{id}"
                    continue
                pattern += "/" + dir
                path = os.path.join(path, dir)
            #print(path)
            if not os.path.exists(path):
                continue
            patterns = []
            for action in actions:
                _pattern = pattern + "/Actions/" + action.strip("#")
                patterns.append((_pattern, ['put']))
            create_node_file(os.path.join(path, "actions.c"), patterns)

if __name__ == '__main__':
    schema_dir = os.getcwd() + "/schema"
    template_dir = os.getcwd() + "/template"

    #url_collections = url_collections_get(schema_dir)
#    print(url_collections)
    #create_template_tree(template_dir, url_collections)
    #create_cmake(template_dir)
    #create_rest_file(template_dir, 1, "/redfish/v1")
    action_list = collect_actions(schema_dir, template_dir)
    for k, v in action_list.items():
        if len(v['actions']) == 0:
            del action_list[k]
    pp = pprint.PrettyPrinter(indent=2)
    pp.pprint(action_list)
    create_action_node(action_list, template_dir)