#include <iostream>

using namespace std;

int field[51][51] = { 0 };
bool visit[51][51];

struct limit{ int x, y; };

void dfs(int x, int y, limit& lim){
    if (visit[y][x] || field[y][x] != 1) return;
    else{
        visit[y][x] = true;
        if (x - 1 >= 0) dfs(x - 1, y, lim);
        if (x + 1 < lim.x) dfs(x + 1, y, lim);
        if (y - 1 >= 0) dfs(x, y - 1, lim);
        if (y + 1 < lim.y) dfs(x, y + 1, lim);
    }
}

void clear_field(int X, int Y){
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++){
            field[y][x] = 0;
            visit[y][x] = false;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, X, Y, K, x, y, count = 0;

    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> X >> Y >> K;
        
        clear_field(X, Y);  // �迭 �� �ʱ�ȭ
        count = 0;  // count �� �ʱ�ȭ
        limit lim = { X, Y };   // ���� ���� �ʱ�ȭ

        // ���� ��ġ �� �ֱ�
        for (int k = 0; k < K; k++){
            cin >> x >> y;
            field[y][x] = 1;
        }

        // dfs ����
        for (int y = 0; y < Y; y++){
            for (int x = 0; x < X; x++){
                if (!visit[y][x] && field[y][x] == 1){
                    dfs(x, y, lim);
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}