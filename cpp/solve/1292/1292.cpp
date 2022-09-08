#include <iostream>

using namespace std;

int main(){
    int n, m, cnt = 1, sum = 0;

    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= i; j++){
            if (cnt > n - 1 && cnt < m + 1){
                sum += i;
            }
            cnt++;
        }
    }

    cout << sum;

    return 0;
}