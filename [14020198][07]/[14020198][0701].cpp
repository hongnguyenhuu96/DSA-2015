#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int** readFile(const char* fileName, int &n, int &m);
void showGraph(int ** graph, int n);
void topoSort(int ** graph,int n, int *visitted, int start, int &numbering, int *label);
void showLabel(int *label, int n);
void showLabelToFile(const char* fileName, int *label, int n);

int main()
{
    int **graph;
    int m, n;
    graph = readFile("network.txt", n, m);
    int *visitted = new int[n + 1];
    int *label = new int[n + 1];
    for(int i = 1; i <= n; i++){
        visitted[i] = false;
        label[i] = 0;
    }
    int numbering = n;
    for(int i = 1; i <= n; i++){
        if(!visitted[i])
            topoSort(graph, n, visitted, i, numbering, label);
    }
    showLabelToFile("network.out", label, n);
}
void showLabelToFile(const char* fileName, int *label, int n){
    ofstream file(fileName);
    for(int i = 1; i<= n; i++){
        file << label[i] << " ";
    }
}

void topoSort(int ** graph,int n, int *visitted, int start, int &numbering, int *label){
    if(!visitted[start]){
        visitted[start] = true;
    }
    for(int i = 1; i <= n; i++){
        if(graph[start][i]){
            if(!visitted[i]){
                topoSort(graph, n, visitted, i, numbering, label);
            }
        }
    }
    label[start] = numbering;
    numbering--;
}

int** readFile(const char* fileName, int &n, int &m){
    ifstream file(fileName);
    file >> n >> m;
    int **graph = new int*[n + 1];
    for(int i = 1; i <= n; i++){
        graph[i] = new int[n + 1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            graph[i][j] = 0;
        }
    }
    while(!file.eof()){
        int u, v;
        file >> u >> v;
        if(file){
            graph[u][v] = 1; // There is a path from u to v
        }
    }
    return graph;
}

void showGraph(int ** graph, int n){
    cout << "    ";
    for(int i = 1; i <= n; i++){
        cout << i << " ";
    }
    cout << endl << endl;
    for(int i = 1; i <= n; i++){
        cout << i << "   ";
        for(int j = 1; j <= n;j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void showLabel(int *label, int n){
    for(int i = 1; i<= n; i++){
        cout << label[i] << " ";
    }
}
