#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <queue>

#define INFINITE 2000000000
using namespace std;


struct Site{
    int minDistance;
    int pre;
};


int** readFile(const char* fileName, int &n, int &m, int &s, int &e);
void showGraph(int ** graph, int n);
void dijktra(int **graph, Site *site, int n, int start);
void printPath(const char* fileName, Site *site, int s, int e);




int main()
{
    int **graph;
    int m, n, s, e;
    graph = readFile("roads.txt", n, m, s, e);
    Site *site = new Site[n + 1];
    dijktra(graph, site, n, s);
    printPath("roads.out", site, s, e);
}

void dijktra(int **graph, Site *site, int n, int start){
    for(int i = 1; i<= n ; i++){
        site[i].minDistance = graph[start][i];
        site[i].pre = start;
    }
    site[start].minDistance = 0;
    vector<int> s; // luu cac dinh da gach (da tim duoc duong di ngan nhat tu start toi)
    bool *checked = new bool[n + 1]; // danh dau cac dinh da bi gach
    for(int i = 1; i <= n; i++){
        checked[i] = false; // chua bi gach
    }
    checked[start] = true; //di tu dinh start nen gach start
    s.push_back(start); // them start vao danh sach dinh da chac chan tim duoc duong ngan nhat toi

    while(n != s.size()){
        int minPath = INFINITE; // khoang cach ngan nhat tu start toi mot dinh trong cac dinh chua bi xoa
        int minVer = start; // u la dinh ma khoang cach tu start toi u nho nhat trong so cac dinh chua bi xoa
        for(int i = 1; i <= n; i++){
            if(checked[i] == false){
                if(site[i].minDistance <= minPath){
                    minPath = site[i].minDistance;
                    minVer = i;
                }
            }
        }
        s.push_back(minVer);
        checked[minVer] = true;

        for(int i = 1; i <= n; i++){
            if(checked[i] == false){
                int temp = minPath + graph[minVer][i];
                if(temp < site[i].minDistance){
                    site[i].minDistance = temp;
                    site[i].pre = minVer;
                }
            }
        }
    }
}

void printPath(const char* fileName, Site *site, int s, int e){
    ofstream file(fileName);
    file << site[e].minDistance << endl;
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

int** readFile(const char* fileName, int &n, int &m, int &s, int &e){
    ifstream file(fileName);
    file >> n >> m >> s >> e; // max n = 1000
    int **graph = new int*[n + 1];
    for(int i = 1; i <= n; i++){
        graph[i] = new int[n + 1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            graph[i][j] = INFINITE;
        }
    }
    while(!file.eof()){
        int u, v;
        int length;
        file >> u >> v >> length; // max length = 1000000
        if(file){
            if(length < graph[u][v]) graph[u][v] = length;
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
