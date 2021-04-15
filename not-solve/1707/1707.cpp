#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[20001];
bool visit[20001];

bool is_bipartite_graph(){
    queue<pair<int, bool>> q;
    q.push(make_pair(0, false));

    while(!q.empty()){
        pair<int, bool> p = q.front();
        q.pop();

        if (!visit[p.first]){
            
        }
    }
}

int main(){
    cin.tie(); cout.tie();
    int T, V, E;
    int first, second;

    cin >> T;
    for (int t = 0; t < T; t++){
        cin >> V >> E;
        for (int e = 0; e < E; e++){
            cin >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }
        if (is_bipartite_graph()){
            
        }
    }

    return 0;
}