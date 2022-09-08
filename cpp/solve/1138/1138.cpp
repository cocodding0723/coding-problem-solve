#include <iostream>

using namespace std;

int main(){
    int N, temp;
    int result[11] = { 0 };

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> temp;

        for (int j = 0; j < temp + 1; j++){
            if (result[j] != 0) temp++;
        }

        result[temp] = i + 1;
    }

    for (int i = 0; i < N; i++) cout << result[i] << ' ';

    return 0;
}