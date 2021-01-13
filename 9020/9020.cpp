// 시간 : 1324ms
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool what_is_decimals[10001];
vector<int> decimals;

void guess(int number){
    int minA = 0, minB = 20000;
    for (int i = 0; i < decimals.size(); i++){
        if (decimals[i] > number) break;
        for (int j = 0; j < decimals.size(); j++){
            if (decimals[j] > number) break;
            else if (decimals[i] + decimals[j] > number) break;
            else if (number == decimals[i] + decimals[j]){
                if (max(minA, minB) - min(minA, minB) > 
                    max(decimals[i], decimals[j]) - min(decimals[i], decimals[j])){
                    minA = decimals[i];
                    minB = decimals[j];  
                }
            }
        }
    }

    cout << min(minA, minB) << ' ' << max(minA, minB) << endl;
}

// 에라토스 테네스의 체
// 출처 : https://marobiana.tistory.com/91
void find_decimals(int max_number){
    // 소수 구하기
    for (int i = 2; i < sqrt(max_number); i++){
        if (what_is_decimals[i]) continue;
        for (int j = i + i; j < max_number; j += i)
            if (!what_is_decimals[j]) {
                what_is_decimals[j] = true;
            }
    }

    for (int i = 2; i < max_number; i++){
        if (!what_is_decimals[i]) decimals.push_back(i);
    }
}

int main(){
    // 추가후 1236ms
    // ---
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);     // 추가후 1252ms
    // --- 

    int T;
    int input_data;
    cin >> T;

    find_decimals(10000);

    for (int i = 0; i < T; i++){
        cin >> input_data;
        guess(input_data);
    }

    return 0;
}