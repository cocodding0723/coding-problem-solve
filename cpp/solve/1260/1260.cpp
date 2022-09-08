#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> *graph;
bool *visit;

// 재귀함수 이용
void dfs(int start){
    cout << start << ' ';
    visit[start] = true;
    for (int i = 0; i < graph[start].size(); i++){
        if (!visit[graph[start][i]]){
            dfs(graph[start][i]);
        }
    }
}

// 스택을 이용해서 하는 것은 좀더 생각해봐야겟음
// void dfs(int start){
//     stack<int> st;
//     st.push(start);

//     while(!st.empty()){
//         int current_node = st.top();
//         st.pop();
//         if (!visit[current_node]){
//             visit[current_node] = true;
//             cout << current_node << ' ';
//             for (int i = graph[current_node].size() - 1; i > 0 ; i--){
//                 int next_node = graph[current_node][i];
//                 if (!visit[next_node]){
//                     st.push(next_node);
//                 }
//             }
//         }
//     }
// }

// queue이용
void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << ' ';

        for (int i = 0; i < graph[node].size(); i++){
            int link_node = graph[node][i];
            if (!visit[link_node]){
                visit[link_node] = true;
                q.push(link_node);
            }
        }
    }
}

void visit_clear(int size){
    for (int i = 0; i < size; i++)
        visit[i] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    int v, n;

    cin >> N >> M >> V;

    graph = new vector<int>[N + 1];
    visit = new bool[N + 1];

    for (int i = 0; i < M; i++){
        cin >> v >> n;
        graph[v].push_back(n);
        graph[n].push_back(v);
    }

    for (int i = 0; i < N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    visit_clear(N + 1);
    cout << endl;
    bfs(V);

    delete[] graph;
    delete visit;

    return 0;
}