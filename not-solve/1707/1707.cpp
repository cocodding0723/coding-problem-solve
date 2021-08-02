#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE{
    int number;
    bool div;
};

int K, V, E, x, y;

void bfs(vector<int> v[]){
    bool visit[20001] = { 0 };
    bool div[20001];
    queue<NODE> q;
    q.push({x, false});

    while(!q.empty()){
        NODE current = q.front();
        q.pop();

        if (!visit[current.number]){
            visit[current.number] = true;
            
            for (int i=0; i < v[current.number].size(); i++){
                NODE next = { v[current.number][i], !current.div };
                if (!visit[next.number]){
                    div[next.number] = !current.div;
                    q.push({ v[current.number][i], !current.div });
                }
                else{
                    if (current.div == div[next.number]){
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "YES" << endl;
}

int main(){
    cin >> K;

    for (int i=0; i<K; i++){
        vector<int> v[20001];

        cin >> V >> E;
        for (int j=0; j<E; j++){
            cin >> x >> y;

            v[x].push_back(y);
            v[y].push_back(x);
        }

        bfs(v);
    }

    return 0;
}