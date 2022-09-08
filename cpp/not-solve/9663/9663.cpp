#include <iostream>

using namespace std;

int input, limit;
int arr[16];
bool visit[16];

void dfs(int n){
    if (!visit[n] && n <= input){
        visit[n] = true;
        cout << n << ' ';
        dfs(n + 1);
        visit[n] = false;
    }
}

int main(){

    cin >> input >> limit;

    dfs(1);

    return 0;
}