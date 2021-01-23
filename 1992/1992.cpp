#include <iostream>

using namespace std;

char arr[65][65];

void quad_tree(int x, int y, int size){
    if (size == 0) return;

    // 분할 확인
    // cout << endl << "x : " << x << ", y : " << y << ", size : " << size << endl;
    // for (int i = 0; i < size; i++){
    //     for (int j = 0; j < size; j++){
    //         cout << arr[i + y][j + x];
    //     }
    //     cout << endl;
    // }

    int zero = 0, one = 0;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (arr[y + i][x + j] == '1') one++;
            else if (arr[y + i][x + j] == '0') zero++;
        }
    }

    if (zero == size * size) cout << '0';
    else if (one == size * size) cout << '1';
    else{
        // 분할 확인
        // cout << "divide" << endl;

        size /= 2;
        
        cout << '(';
        quad_tree(x, y, size);
        quad_tree(x + size, y, size);
        quad_tree(x, y + size, size);
        quad_tree(x + size, y + size, size);
        cout << ')';
    }
}

int main(){
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    quad_tree(0, 0, N);

    return 0;
}