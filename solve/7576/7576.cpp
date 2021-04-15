#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct POINT{ int x, y, count; };

int map[1001][1001];
bool visit[1001][1001];
int X, Y, count = 0;
queue<POINT> q;
vector<bool*> check_point;

bool check_end();

void bfs(){
    POINT current_node;
    while(!q.empty()){
        current_node =  q.front();
        q.pop();

        // 여기부분을 수정하면 더 빨라질것 같은데...
        // 어뜨캐해야하나...

        if (!visit[current_node.y][current_node.x]){
            visit[current_node.y][current_node.x] = true;
            
            if (current_node.x + 1 < X && map[current_node.y][current_node.x + 1] == 0){
                q.push({current_node.x + 1, current_node.y, current_node.count + 1});
            }
            if (current_node.y - 1 >= 0 && map[current_node.y - 1][current_node.x] == 0){
                q.push({current_node.x, current_node.y - 1, current_node.count + 1});
            }
            if (current_node.y + 1 < Y && map[current_node.y + 1][current_node.x] == 0){
                q.push({current_node.x, current_node.y + 1, current_node.count + 1});
            }
            if (current_node.x - 1 >= 0 && map[current_node.y][current_node.x - 1] == 0){
                q.push({current_node.x - 1, current_node.y, current_node.count + 1});
            }
        }
    }

    if (check_end()) {
        cout << -1;
        return;
    }

    if (current_node.count == 0) {
        cout << 0 << endl;
        return;
    }

    cout << current_node.count - 1;
}

bool check_end(){
    if (check_point.size() == 0) return false;

    int count = 0;
    for (int i = 0; i < check_point.size(); i++){
        if (*(check_point[i])) count++;
        else return true;
    }

    if (count == check_point.size()) return false;
    else return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X >> Y;

    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++){
            cin >> map[y][x];
            if (map[y][x] == 1) 
                q.push({x, y, 0});
            if (map[y][x] == 0 || map[y][x] == 1) check_point.push_back(&visit[y][x]);
        }

    bfs();

    return 0;
}