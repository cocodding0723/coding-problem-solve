#include <iostream>
#include <queue>

using namespace std;

int N, K;
int pos[100001];
bool visit[100001];

void bfs(){
    queue<pair<int, int>> q;
    int count = 0;
    q.push(make_pair(N, count));

    while(!q.empty()){
        pair<int, int> v = q.front();
        q.pop();

        if (v.first == K) {
            cout << v.second;
            return;
        }
        if (v.first < 0 || v.first > 100000) continue;
        else if (!visit[v.first]){
            visit[v.first] = true;

            q.push(make_pair(v.first - 1, v.second + 1));
            q.push(make_pair(v.first + 1, v.second + 1));
            q.push(make_pair(2 * v.first, v.second + 1));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    bfs();

    return 0;
}