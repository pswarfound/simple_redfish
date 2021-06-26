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

    return uri_nodes;
#        print(nodes[3:])


def create_rest_file(path, lv, uri_pattern):
    if lv == 1:
        cmd = 'touch ' + path + "/redfish_root.c"
        child = subprocess.Popen(cmd, shell=True)

    d = os.listdir(path)
    print("========" + path)
    print(d)
    is_collection = False
    

    for f in d:
        cur_path = os.path.join(path, f)
        if os.path.isdir(cur_path):
            uri_pattern += f
            if os.path.exists(os.path.join(cur_path, "id")):
                is_collection = True

            if is_collection:
                cmd = 'touch ' + cur_path + "/collection.c"
                child = subprocess.Popen(cmd, shell=True)
                f = open(cur_path + "/collection.c", 'w')
                f.write("#include \"rest_node.h\"\n")
                f.write("REST_NODE(\"" + uri_pattern + "\",,);")
                f.close()
                uri_pattern += "/{id}"
            create_rest_file(cur_path, lv + 1, uri_pattern)
    
if __name__ == '__main__':
    url_collections = url_collections_get()
#    print(url_collections)
    template_info = parse_url(url_collections)
    #print(template_info)
    create_rest_file(os.getcwd() + "/template", 1, "/redfish/v1")