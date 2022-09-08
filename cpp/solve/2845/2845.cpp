#include <iostream>

using namespace std;

int main(){
    int n, m, input;

    cin >> n >> m;

    n *= m;

    for (int i = 0; i < 5; i++){
        cin >> input;
        cout << input - n << ' ';
    }

    return 0;
}