#include <iostream>

using namespace std;

int main(){
    int n, k, water = 0, i = 1, div_num;

    cin >> n >> k;

    while(div_num < n){
        div_num = 1 << i;
    }

    cout << i;

    return 0;
}