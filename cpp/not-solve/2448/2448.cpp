// https://www.acmicpc.net/problem/2448

#include <iostream>

using namespace std;

int N;
int arr[5000][5000];

void solution(int n){
    
}

int main(){
    scanf("%d", &N);

    for (int i = 1; i < N; i++){
        for (int j = 0; j < N - i - 1; j++) arr[i][j] = 0;
        for (int k = 0; k < 2 * i - 1; k++) arr[i][k] = 1;
    }

    return 0;
}