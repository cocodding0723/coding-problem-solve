// 문제 : https://www.acmicpc.net/problem/2670
#include <iostream>

using namespace std;

double arr[10001];
double result;
int N;

int main(){
    cin >> N;
    cin >> arr[0];

    result = arr[0];

    for (int i = 1; i < N; i++){
        cin >> arr[i];
        
        arr[i] = max(arr[i], arr[i] * arr[i - 1]);

        result = max(arr[i], result);
    }

    printf("%.3f", result);

    return 0;
}