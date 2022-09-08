#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, current, total = 0;
int arr[101];
bool visit[101];

void dfs(int n, int count = 1){
    if (visit[n]){
        return;
    }

    visit[n] = true;

    if (n == current){
        total += count;
    }
    else{
        dfs(arr[n], count + 1);
    }
}

int main(){
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++){
        current = i;
        dfs(arr[i]);
    }

    cout << total << endl;

    return 0;
}