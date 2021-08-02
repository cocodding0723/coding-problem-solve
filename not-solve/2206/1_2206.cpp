#include <iostream>
#include <queue>

using namespace std;

int X, Y;
char map[1001][1001];
bool visit[1001][1001];
int c_x[4] = { 1, -1, 0, 0 };
int c_y[4] = { 0, 0, 1, -1 };

struct BLOCK{
    int x, y, count;
    bool is_broken;
};

void bfs(){
    queue<BLOCK> q;
    q.push({0, 0, 0, false});

    while(!q.empty()){
        BLOCK b = q.front();
        q.pop();

        if (!visit[b.y][b.x]){
            visit[b.y][b.x] = true;

             cout << b.count << endl;

            if (b.x == X - 1 && b.y == Y - 1){
                cout << b.count;
                return;
            }

            for (int i = 0; i < 4; i++){
                int nx = b.x + c_x[i];
                int ny = b.x + c_y[i];

                if (nx < 0 || ny < 0 || nx >= X || ny >= Y) continue;
                else if (b.is_broken && map[ny][nx] == '1') continue;
                else if (!b.is_broken && map[ny][nx] == '1'){
                    q.push({nx, ny, b.count + 1, true});
                }
                else if (map[ny][nx] == '0'){
                    q.push({nx, ny, b.count + 1, b.is_broken});
                }
            }
        }
    }
}

int main(){
    cin >> X >> Y;

    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            cin >> map[y][x];
    
    bfs();

    return 0;
}