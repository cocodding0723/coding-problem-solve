#include <iostream>

using namespace std;

int arr[129][129];
int white_count = 0, blue_count = 0;

void cut_paper(int x, int y, int size){
    if (size == 0) return;

    int white = 0, blue = 0;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (arr[y + i][x + j] == 1) blue++;
            else if (arr[y + i][x + j] == 0) white++;
        }
    }

    if (blue == size * size) blue_count++;
    else if (white == size * size) white_count++;
    else{
        size /= 2;

        cut_paper(x, y, size);
        cut_paper(x + size, y, size);
        cut_paper(x, y + size, size);
        cut_paper(x + size, y + size, size);
    }
}

int main(){
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    cut_paper(0, 0, N);

    cout << white_count << endl << blue_count;

    return 0;
}