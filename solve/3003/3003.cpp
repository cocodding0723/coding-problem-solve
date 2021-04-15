#include <iostream>

using namespace std;

int main(){
    int arr[8];
    for (int i = 0; i < 6; i++) cin >> arr[i];

    for (int i = 0; i < 2; i++) cout << 1 - arr[i] << ' ';
    for (int i = 2; i < 5; i++) cout << 2 - arr[i] << ' ';
    cout << 8 - arr[5];

    return 0;
}