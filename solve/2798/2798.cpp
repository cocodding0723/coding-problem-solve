#include <iostream>

using namespace std;

int main(){
    int n, m, result, sub = 100001, temp;
    int *arr;

    cin >> n >> m;

    arr = new int[n];

    for (int i = 0; i < n; i++){
        cin >> temp;
        arr[i] = temp;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            for (int k = 0; k < n; k++){
                if (i == k || k == j) continue;

                temp = arr[i] + arr[j] + arr[k];
                if (m >= temp && sub > m - temp){
                    result = temp;
                    sub = m - temp;
                }
            }
        }
    }

    cout << result;

    delete arr;

    return 0;
}