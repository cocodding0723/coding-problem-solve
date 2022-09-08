#include <iostream>

using namespace std;

int arr[100001];

int main(){
    int n;

    cin >> n;

    arr[0] = 3;
    arr[1] = 7;
    
    if (n < 2) cout << arr[n - 1];
    else{
        for (int i = 2; i < n; i++){
            arr[i] = (arr[i - 1] * 2 + arr[i - 2]) % 9901;
        }

        cout << arr[n - 1];
    }
}