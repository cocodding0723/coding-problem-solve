#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool visit[9] = { 0 };

void dfs(int cnt){
    if (cnt == M){
        for (int i = 0; i < M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");

        return;
    }
    
    for (int i = 1; i <= N; i++){
        if (!visit[i]){
            visit[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            visit[i] = false;
        }
    }
}

int main(){    
    scanf("%d %d", &N, &M);

    dfs(0);

    return 0;
}