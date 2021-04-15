// Âü°í : https://sihyungyou.github.io/baekjoon-1932/

#include <iostream>

using namespace std;

int arr[500][500];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, result = 0;

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < N; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0) arr[i][j] += arr[i - 1][j];
            else if (j == i) arr[i][j] += arr[i - 1][j - 1];
            else arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);

            result = max(result, arr[i][j]);
        }
    }

    cout << result << endl;

    return 0;
}