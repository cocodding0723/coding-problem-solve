#include <iostream>
#include <math.h>

using namespace std;

int arr[2190][2190];
int one = 0, zero = 0, minus_one = 0;

void divide_paper(int x, int y, int size){
    int count_one = 0, count_zero = 0, count_minus_one = 0;
    bool flag = false;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (arr[y + i][x + j] == 1) count_one++;
            else if (arr[y + i][x + j] == 0) count_zero++;
            else if (arr[y + i][x + j] == -1) count_minus_one++;
        }
        if (count_one > 0){
            if (count_zero != 0 || count_minus_one != 0) break;
        }
        else if (count_zero > 0){
            if (count_one != 0 || count_minus_one != 0) break;
        }
        else if (count_minus_one > 0){
            if (count_one != 0 || count_zero != 0) break;
        }
    }

    if (count_one == size * size) one++;
    else if (count_zero == size * size) zero++;
    else if (count_minus_one == size * size) minus_one++;
    else{
        size /= 3;
        divide_paper(x, y, size);
        divide_paper(x + size, y, size);
        divide_paper(x + (size * 2), y, size);
        divide_paper(x, y + size, size);
        divide_paper(x + size, y + size, size);
        divide_paper(x + (size * 2), y + size, size);
        divide_paper(x, y + (size * 2), size);
        divide_paper(x + size, y + (size * 2), size);
        divide_paper(x + (size * 2), y + (size * 2), size);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    divide_paper(0, 0, N);
    
    cout << minus_one << endl << zero << endl << one;

    return 0;
}