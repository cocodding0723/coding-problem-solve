#include <iostream>
#include <queue>

// Âü°í : https://jun-itworld.tistory.com/20

int X, Y;
char map[101][101];
bool visit[101][101];

using namespace std;

struct POINT{ int x, y, distance; };

void bfs(POINT point){
    queue<POINT> q;
    int count = 0;

    q.push(point);

    while(!q.empty()){
        POINT current_point = q.front();
        q.pop();

        if (current_point.y == Y - 1 && current_point.x == X - 1){
            cout << current_point.distance;
            return;
        }

        if (!visit[current_point.y][current_point.x]){
            visit[current_point.y][current_point.x] = true;

            if (current_point.x + 1 < X && map[current_point.y][current_point.x + 1] == '1'){
                q.push({current_point.x + 1, current_point.y, current_point.distance + 1});
            }
            if (current_point.y - 1 >= 0 && map[current_point.y - 1][current_point.x] == '1'){
                q.push({current_point.x, current_point.y - 1, current_point.distance + 1});
            }
            if (current_point.y + 1 < Y && map[current_point.y + 1][current_point.x] == '1'){
                q.push({current_point.x, current_point.y + 1, current_point.distance + 1});
            }
            if (current_point.x - 1 >= 0 && map[current_point.y][current_point.x - 1] == '1'){
                q.push({current_point.x - 1, current_point.y, current_point.distance + 1});
            }
        }
    }
}

int main(){
    cin >> Y >> X;

    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            cin >> map[y][x];

    bfs({0, 0, 1});

    return 0;
}