#include <iostream>

using namespace std;

int dp[10000002];
int T, temp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 3; i <= T; i++){
        if (i % 3 == 0 && i % 2 == 0){ 
            temp = min(dp[i - 1], dp[i / 2]);
            temp = min(temp, dp[i / 3]);
        }
        else if (i % 3 == 0){
            temp = min(dp[i - 1], dp[i / 3]);
        }
        else if (i % 2 == 0){
            temp = min(dp[i - 1], dp[i / 2]);
        }
        else temp = dp[i - 1];
        dp[i] = temp + 1;
    }

    cout << dp[T];
    
    return 0;
}