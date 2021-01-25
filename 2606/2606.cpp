#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> *graph;
bool *visit;
int count = 0;

void dfs(int start){
    if (!visit[start]){
        ::count++;
        visit[start] = true;
        for (int i = 0; i < graph[start].size(); i++){
            dfs(graph[start][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, V;
    int n, v;

    cin >> N >> V;

    graph = new vector<int>[N + 1];
    visit = new bool[N + 1];

    for (int i = 0; i < V; i++){
        cin >> n >> v;

        graph[n].push_back(v);
        graph[v].push_back(n);
    }

    dfs(1);

    cout << ::count - 1;

    delete[] graph;
    delete visit;

    return 0;
}