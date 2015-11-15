#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;


struct Node{
    int index;
    int depth = -1;
    Node *parent = NULL;
    vector<Node*> children;
};

Node* readFile(const char* fileName, int &n ,int &m);
int depth(Node* vertices, const int &v);
bool isRoot(Node* vertices, const int &u);
int heightTree(Node* vertices,const int &n);
void sortChildren(Node* vertices, const int &v);

int main()
{
    int n, m;
    Node* vertices = readFile("tree.txt", n, m);
    for(int i = 1; i <= n; i++){
        cout << depth(vertices, i) << " ";
    }
}

Node* readFile(const char* fileName, int &n ,int &m){
    ifstream file(fileName);
    file >> n >> m;
    Node* vertices = new Node[n + 1];
    for(int i = 0; i <= n; i++){
        vertices[i].index = i;
    }
    while(!file.eof()){
        int u, v;
        file >> u >> v;
        if(file){
            Node *temp = vertices + v;
            vertices[u].children.push_back(temp);
            vertices[v].parent = vertices + u;
        }
    }
    for(int i = 1; i <= n; i++){
        sortChildren(vertices, i);
    }
    return vertices;
}

int depth(Node* vertices, const int &v){
    if(vertices[v].depth != -1) return vertices[v].depth;
    if(isRoot(vertices, v)){
        return 0;
    }
    else{
        int depthParent;
        if(vertices[v].parent->depth == -1){
            depthParent = depth(vertices, vertices[v].parent->index);
        }
        return 1 + depthParent;
    }
}

bool isRoot(Node* vertices, const int &u){
    if(vertices[u].parent == NULL) return true;
    else return false;
}


int heightTree(Node* vertices,const int &n){
    int height = 0;
    for(int i = 1; i <= n; i++){
        int temp = depth(vertices, i);
        if(height < temp) height = temp;
    }
    return height;
}

void sortChildren(Node* vertices, const int &v){
    int numChildren = vertices[v].children.size();
    for(int i = 0; i < numChildren - 1; i++){
        for(int j = i + 1; j < numChildren; j++){
            if(vertices[v].children[i]->index > vertices[v].children[j]->index){
                Node* temp = vertices[v].children[i];
                vertices[v].children[i] = vertices[v].children[j];
                vertices[v].children[j] = temp;
            }
        }
    }
}
