#include <iostream>
#include <queue>

using namespace std;

struct POINT{
    int x, y;
} typedef PT;

PT next_points[8] = {
    { 2, 1 },
    { 2, -1 },
    { 1, 2 },
    { 1, -2 },
    { -2, 1 },
    { -2, -1 },
    { -1, 2 },
    { -1, -2 }
};

// bool visits[300][300];

int bfs(PT start, PT target, int size);
bool operator==(PT& lhs, PT& rhs);
void clear_visit(int size);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, size;
    PT start, target;

    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> size;                    // 체스판 크기 설정
        cin >> start.x >> start.y;      // 시작 지점
        cin >> target.x >> target.y;    // 끝나는 지점

        cout << bfs(start, target, size) << '\n';
    }

    return 0;
}

int bfs(PT start, PT target, int size){
    if (start == target) return 0;

    bool visits[300][300] = { 0 };

    int result = 0;
    pair<PT, int> temp;
    PT next;

    queue<pair<PT, int>> q;

    q.push(make_pair(start, 0));

    while(!q.empty()){
        temp = q.front();  
        q.pop();

        if (!visits[temp.first.y][temp.first.x]){
            visits[temp.first.y][temp.first.x] = true;

            for (int i = 0; i < 8; i++){
                next = { temp.first.x + next_points[i].x, temp.first.y + next_points[i].y };
                        
                if (next == target){
                    return temp.second + 1;
                }

                if (next.x < size && next.y < size && next.x > -1 && next.y > -1){
                    q.push(make_pair(next, temp.second + 1));
                }
            }
        }
    }

    return result;
}

// void clear_visit(int size){
//     for (int i = 0; i < size * size; i++){
//         visits[i / size][i % size] = false;
//     }
// }

bool operator==(PT& lhs, PT& rhs){
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}