#include <iostream>

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

    int N, G, first_ring, other_ring;

    cin >> N;

    cin >> first_ring;

    N -= 1;

    for (int i = 0; i < N; i++){
        cin >> other_ring;
        G = gcd(first_ring, other_ring);
        cout << first_ring / G << '/' << other_ring / G << '\n';
    }

    return 0;
}