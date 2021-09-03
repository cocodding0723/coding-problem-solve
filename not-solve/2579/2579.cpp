// https://www.acmicpc.net/problem/2579
#include <iostream>

using namespace std;

int N, continuousCount = 0;
int arr[301];

int main(){
    cin >> N;
    
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = N - 1; i > 2; i--){
        if (arr[i - 1] + arr[i] > arr[i - 2] + arr[i]){
            
        }
    }

    return 0;
}