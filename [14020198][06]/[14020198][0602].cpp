#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int** readFile(const char* fileName, int &n, int &m);
void showGraph(int ** graph, int n);
void depthFirstSearch(int ** graph, int n, int *visitted, int start);

int main()
{
    int **graph;
    int m, n;
    graph = readFile("network.inp", n, m);
    int *visitted = new int[n + 1];
    for(int i = 1; i <= n; i++){
        visitted[i] = false;
    }
    for(int i = 1; i <= n; i++){
        if(!visitted[i])
            depthFirstSearch(graph, n, visitted, i);
    }
}

void depthFirstSearch(int ** graph,int n, int *visitted, int start){
    if(!visitted[start]){
        cout << start << " ";
        visitted[start] = true;
    }
    for(int i = 1; i <= n; i++){
        if(graph[start][i]){
            if(!visitted[i]){
                depthFirstSearch(graph, n, visitted, i);
            }
        }
    }
}

int** readFile(const char* fileName, int &n, int &m){
    ifstream file(fileName);
    file >> n >> m;
    int **graph = new int*[n + 1]; // từ đỉnh [i][j] i đi thăm j
    for(int i = 1; i < n + 1; i++){
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
            graph[u][v] = 1;
            graph[v][u] = 1;
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
