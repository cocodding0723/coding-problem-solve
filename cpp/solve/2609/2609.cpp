#include <iostream>
#include <math.h>

using namespace std;

int gcd(int A, int B){
    int m = max(A, B);
    int n = min(A, B);

    int remainder = m % n;
    while(remainder != 0){
        m = n;
        n = remainder;
        remainder = m % n;
    }

    return n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, G;

    cin >> A >> B;

    G = gcd(A, B);

    cout << G << '\n' << (A * B / G);

    return 0;
}