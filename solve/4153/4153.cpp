#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[3];

int main(){
    while(true){
        cin >> arr[0] >> arr[1] >> arr[2];

        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;

        sort(arr, arr + 3);

        if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2))
            cout << "right" << endl;
        else cout << "wrong" << endl;
    }

    return 0;
}