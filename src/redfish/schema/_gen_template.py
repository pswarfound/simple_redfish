import os
import sys
import subprocess

def url_collections_get(_path = None):
    if _path is None:
        _path = os.getcwd() + "/"
    #cmd = 'grep -Rn \\"/redfish/v1 ' + _path + '*.json'
    cmd = 'grep -Rn \\"/redfish/v1 ' + _path + '*.json|awk \'{print $2}\''
    #print(cmd)
    child = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
   # child.wait()
    return child.stdout.read()


def parse_url(url_collections):
    lines = url_collections.split("\n")
    uri_nodes = []

    for line in lines:
        line = line.strip()
        line = line.strip(",")
        line = line.strip("\"")
        
        nodes = line.split("/")
        if len(nodes) > 0:
            uri_nodes.append(nodes[1:])
        path = os.getcwd() + "/template"
        for node in nodes[3:]:
            if len(node) == 0:
                continue
            if "{" in node:
                continue;
            path = os.path.join(path, node)
#        print(path)
        cmd = 'mkdir -p ' + path
        child = subprocess.Popen(cmd, shell=True)

        path = os.getcwd() + "/template"
        for node in nodes[3:]:
            if len(node) == 0:
                continue
            if "{" in node:
#                print(path)
                cmd = 'touch ' + path + "/id"
                child = subprocess.Popen(cmd, shell=True)
                continue;
            path = os.path.join(path, node)
    return uri_nodes
#        print(nodes[3:])

def create_node_file(path, uri_list):
    cfile = open(path, 'w')
    cfile.write("""
#include <stdio.h>
#include \"rest_node.h\"
#include \"http.h\"

""")
    for uri in uri_list:
        node_start = uri.rfind("/")
        node_parent_start = None
        if "{id}" in uri[node_start + 1:]:
            node_parent_start = uri[:node_start].rfind("/")
        if node_parent_start is None:
            ff = uri[node_start + 1:].replace("-", "_")
        else:
            ff = uri[node_parent_start + 1:node_start].replace("-", "_") + "_id"

        cfile.write("""
static int rest_""" + ff.lower() + """_handler(void *p, rest_node_rw_t *rw)
{
    printf("%s %d\\n", __func__, __LINE__);

    switch(http_method_get(p)) {
        case HTTP_METHOD_GET:
            return 0;
        default:
            return -1;
    }
}
""")
        cfile.write("\n")
        cfile.write("REST_BIND(\"" + uri + "\", HTTP_METHOD_GET, rest_" + ff.lower() + "_handler);")
        cfile.write("\n")
    cfile.close()

def create_rest_file(path, lv, uri_pattern):

    is_collection = False

    if lv != 1:
        create_node_file(path + "/node.c", [uri_pattern])
        if os.path.exists(os.path.join(path, "id")):
            uri_pattern += "/{id}"
            create_node_file(path + "/node_id.c", [uri_pattern])

    d = os.listdir(path)
    for f in d:
        cur_path = os.path.join(path, f)
        if os.path.isdir(cur_path):
            cur_uri_pattern = uri_pattern + "/" + f
            create_rest_file(cur_path, lv + 1, cur_uri_pattern)

def create_cmake(path):
    cmd = "touch " + path + "/CMakeLists.txt"
    subprocess.Popen(cmd, shell=True)
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

    list_dirs = os.walk(path) 
    for root, dirs, files in list_dirs: 
        for d in dirs: 
            p = os.path.join(root, d)
            p = p[len(path):]
            f.write("aux_source_directory(${CMAKE_CURRENT_LIST_DIR}" + p + " _SRC)\n")
    f.write('''
target_sources(${PROJECT_NAME}
    PRIVATE
    ${_SRC}
)
    ''')
    f.close()

if __name__ == '__main__':
    url_collections = url_collections_get()
#    print(url_collections)
    template_info = parse_url(url_collections)
    #print(template_info)
    create_cmake(os.getcwd() + "/template")
    create_rest_file(os.getcwd() + "/template", 1, "/redfish/v1")