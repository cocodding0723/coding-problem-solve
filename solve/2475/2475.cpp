#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    int result = 0;

    for (int i = 0; i < 5; i++){
        cin >> n;
        result += pow(n, 2);
    }

    cout << result % 10;
    
    return 0;
}