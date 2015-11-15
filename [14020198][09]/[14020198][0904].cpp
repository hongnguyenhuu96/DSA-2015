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
void postOrder(Node* vertices, const int &v);
void sortChildren(Node* vertices, const int &v);
int findRoot(Node* vertices, const int &n);
bool isRoot(Node* vertices, const int &u);

int main()
{
    int n, m;
    Node* vertices = readFile("tree.txt", n, m);
    int root = findRoot(vertices, n);
    postOrder(vertices, root);
}


bool isRoot(Node* vertices, const int &u){
    if(vertices[u].parent == NULL) return true;
    else return false;
}

int findRoot(Node* vertices, const int &n){
    for(int i = 1; i <= n; i++){
        if(isRoot(vertices, i)) return i;
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

void postOrder(Node* vertices, const int &v){
    for(int i = 0; i < vertices[v].children.size(); i++){
        postOrder(vertices, vertices[v].children[i]->index);
    }
    cout << v << " ";
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
