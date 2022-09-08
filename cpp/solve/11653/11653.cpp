#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool what_is_decimals[10000001];

// 에라토스 테네스의 체
// 출처 : https://marobiana.tistory.com/91
void find_decimals(int max_number){
    // 소수 구하기
    for (int i = 2; i <= sqrt(max_number); i++){
        if (what_is_decimals[i]) continue;
        for (int j = i + i; j <= max_number; j += i)
            if (!what_is_decimals[j]) {
                what_is_decimals[j] = true;
            }
    }
}

// 소인수 분해
void factorization(int number){
    int i = 2;
    while(number != 1){
        if (number % i == 0 && !what_is_decimals[i]){
            number /= i;
            cout << i << endl;
        }
        else{
            i++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    find_decimals(N);
    factorization(N);

    return 0;
}