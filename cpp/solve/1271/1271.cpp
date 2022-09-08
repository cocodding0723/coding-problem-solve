#include <iostream>

using namespace std;

int main(){
    long long money, n;

    cin >> money >> n;

    if (n == 0){
        cout << 0 << endl << n;
        return 0;
    }

    cout << money / n << endl << money % n;

    return 0;
}