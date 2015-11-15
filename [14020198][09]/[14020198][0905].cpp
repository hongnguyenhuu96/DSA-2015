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
    bool hasLeft(){
        return (children.size() >= 1);
    }
    bool hasRight(){
        return (children.size() == 2);
    }
};
Node* readFile(const char* fileName, int &n ,int &m);
void sortChildren(Node* vertices, const int &v);
bool checkBinaryTree(Node* vertices, const int &n);
int findRoot(Node* vertices, const int &n);
bool isRoot(Node* vertices, const int &u);
bool inOrder(Node* vertices, const int &v);

int main()
{
    int n, m;
    Node* vertices = readFile("tree.txt", n, m);
    int root = findRoot(vertices, n);
    if(checkBinaryTree(vertices, n)){
        inOrder(vertices, root);
    }
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

bool checkBinaryTree(Node* vertices, const int &n){
    for(int i = 1; i <= n; i++){
        if(vertices[i].children.size() > 2) return false;
    }
    return true;
}

bool inOrder(Node* vertices, const int & v){
    if(vertices[v].hasLeft()){
        inOrder(vertices, vertices[v].children[0]->index);
    }
    cout << v << " ";
    if(vertices[v].hasRight()){
        inOrder(vertices, vertices[v].children[1]->index);
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

