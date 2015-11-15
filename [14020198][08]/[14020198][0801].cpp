#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

struct Site{
    int distance;
    int pre;
};

struct Edge{
    int length;
    int u, v;
};

#define INFINITE 2000000000

Edge* readFile(const char* fileName, int &n, int &m, int &s, int &e);
void bellmanFord(Edge *edges, Site *site, int n, int m, int s);
void printPath(const char* fileName, Site *site, int s, int e);


int main()
{
    int n, m, s, e;
    Edge *edges = readFile("dirty.txt", n, m, s, e);
    Site *site = new Site[n + 1];
    bellmanFord(edges, site, n, m, s);
    printPath("dirty.out", site, s, e);
}



void bellmanFord(Edge *edges, Site *site, int n, int m, int s){
    for(int i = 1; i <= n; i++){
        site[i].distance = INFINITE;
        site[i].pre = 0;
    }
    site[s].distance = 0;
    for(int i = 1; i <= n - 1; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int r = site[u].distance + edges[j].length;
            if(r < site[v].distance){
                site[v].distance = r;
                site[v].pre = u;
            }
        }
    }
}

void printPath(const char* fileName, Site *site, int s, int e){
    ofstream file(fileName);
    file << site[e].distance << endl;
    stack<int> st;
    st.push(e);
    int i = e;
    while(site[i].pre != s){
        st.push(site[i].pre);
        i = site[i].pre;
    }
    st.push(s);
    while(!st.empty()){
        file << st.top() << " ";
        st.pop();
    }
}

Edge* readFile(const char* fileName, int &n, int &m, int &s, int &e){
    ifstream file(fileName);
    file >> n >> m >> s >> e; // max n = 1000
    Edge *edges = new Edge[m];
    int i = 0;
    while(!file.eof()){
        int u, v, length;
        file >> u >> v >> length; // max length = 1000000
        if(file){
            edges[i].u = u;
            edges[i].v = v;
            edges[i].length = length;
            i++;
        }
    }
    return edges;
}
