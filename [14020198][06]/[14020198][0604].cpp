
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int** readFile(const char* fileName, int &n, int &m);
void showGraph(int ** graph, int n);
void breadthFirstSearch(int ** graph, int n, int *visitted, int start);

int main()
{
    int count = 0;
    int **graph;
    int m, n;
    graph = readFile("network.inp", n, m);
    int *visitted = new int[n + 1];
    for(int i = 1; i <= n; i++){
        visitted[i] = false;
    }
    for(int i = 1; i <= n; i++){
        if(!visitted[i]){
            count++;
            breadthFirstSearch(graph, n, visitted, i);
        }
    }
    cout << count;
}

void breadthFirstSearch(int ** graph,int n, int *visitted, int start){
    queue<int> q;
    q.push(start);
    if(!visitted[start]){
        // visit start
        visitted[start] = true;
    }
    while(!q.empty()){
        int w = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(graph[w][i] == 1){
                if(!visitted[i]){
                    // visit i
                    visitted[i] = true;
                    q.push(i);
                }
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
