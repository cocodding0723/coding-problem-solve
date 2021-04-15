#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct POINT{
    int x, y, h, c;
};

queue<POINT> q;
vector<bool*> check_points;
int map[101][101][101] = { 0 };
bool visit[101][101][101] = { 0 };

POINT map_size;

int check_x[] = { 1, -1, 0, 0, 0, 0 };
int check_y[] = { 0, 0, 1, -1, 0, 0 };
int check_h[] = { 0, 0, 0, 0, 1, -1 };

bool is_visit(POINT& point){
    if (visit[point.h][point.y][point.x]) return true;
    else return false;
}

bool check_all_visit(){
    for (int i = 0; i < check_points.size(); i++){
        if (!(*check_points[i])) return false;
    }

    return true;
}

void bfs(){
    POINT cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();

        if (!is_visit(cur)){
            visit[cur.h][cur.y][cur.x] = true;

            for (int i = 0; i < 6; i++){
                int nh = cur.h + check_h[i];
                int ny = cur.y + check_y[i];
                int nx = cur.x + check_x[i];

                if ((nh < 0 || nh >= map_size.h) || (ny < 0 || ny >= map_size.y) || (nx < 0 || nx >= map_size.x)){
                    continue;
                }
                else{
                    q.push({ nx, ny, nh, cur.c + 1 });
                }
            }
        }
    }

    if (check_all_visit()){
        cout << cur.c - 1;
    }
    else{
        cout << -1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> map_size.x >> map_size.y >> map_size.h;

    for (int h = 0; h < map_size.h; h++)
        for (int y = 0; y < map_size.y; y++)
            for (int x = 0; x < map_size.x; x++){
                cin >> map[h][y][x];
                if (map[h][y][x] == 1) {
                    q.push({ x, y, h, 0 });
                    check_points.push_back(&visit[h][y][x]);
                }
                if (map[h][y][x] == 0){
                    check_points.push_back(&visit[h][y][x]);
                }
            }

    bfs();

    return 0;
}
