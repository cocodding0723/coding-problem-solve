#include <iostream>
#include <queue>

using namespace std;

int N, M, x, y;
int arr[1001][1001];
int visit[1001][1001];
int lx[] = { 1, -1, 0, 0 };
int ly[] = { 0, 0, 1, -1 };

struct STATE{
    int x;
    int y;
    bool breakWall = false;
    int walk = 0;
};

void bfs(){
    queue<STATE> q;
    q.push({ 0, 0, false, 1 });

    while(!q.empty()){
        STATE state = q.front();
        q.pop();

        if (state.x == M - 1 && state.y == N - 1){
            cout << state.walk;
            return;
        }

        if (!visit[state.y][state.x]){
            visit[state.y][state.x] = true;

            for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                    x = state.x + lx[j];
                    y = state.y + ly[i];

                    if (x > -1 && x < M && y > -1 && y < N){
                        if (arr[y][x] == 0){
                            q.push({ x, y, state.breakWall, state.walk + 1 });
                        }
                    }
                }
            }
        }
    }

    cout << -1;
}

int main(){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    bfs();

    return 0;
}