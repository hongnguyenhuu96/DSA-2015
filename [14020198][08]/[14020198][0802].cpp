#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge{
    int x, y;
    int length;
};

bool compare(const Edge &x, const Edge &y){
    return x.length < y.length;
}

Edge* readFile(const char* fileName, int &n, int &m){
    ifstream file(fileName);
    file >> n >> m;
    Edge *edges = new Edge[m];
    int i = 0;
    while(!file.eof()){
        int x, y, length;
        file >> x >> y >> length;
        if(file){
            edges[i].x = x;
            edges[i].y = y;
            edges[i].length = length;
            i++;
        }
    }
    return edges;
}

vector<Edge> kruskal(Edge *edges,const int &n, const int &m, int &totalCost){
    totalCost = 0;
    vector<Edge> T;
    sort(edges, edges + m, compare);
    int *parent = new int[n + 1];
    int *size = new int[n + 1];
    for(int i = 1; i < n + 1; i++){
        parent[i] = i;
        size[i] = 1;
    }
    int k = 0;
    int i = 0;
    do{
        int rootX = edges[i].x;
        int rootY = edges[i].y;
        while(rootX != parent[rootX]) rootX = parent[rootX]; // find(x)
        while(rootY != parent[rootY]) rootY = parent[rootY]; // find(y)

        if(rootX != rootY){
            T.push_back(edges[i]);
            totalCost += edges[i].length;
            // union
            if(size[rootX] < size[rootY]){
                parent[rootX] == rootY;
                size[rootY] += size[rootX];
            }
            else{
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
            k++;
        }
        i++;
    } while(k < n - 1);
    return T;
}

void printFile(const char* fileName, vector<Edge> T, const int& totalCost){
    ofstream file(fileName);
    file << totalCost << endl;
    int i = 0;
    while(i < T.size()){
        file << T[i].x << " " << T[i].y << " " << T[i].length << endl;
        i++;
    }
}

int main(){
    int n, m, totalCost;
    Edge* edges = readFile("connection.txt", n, m);
    vector<Edge> T = kruskal(edges, n, m, totalCost);
    printFile("connection.out", T, totalCost);
    return 0;
}
