#include <iostream>

using namespace std;

int n, x;
int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int start = 0, end = 0, sum = 0, result;

    cin >> n >> x;

    result = x + 1;

    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    sum += arr[0];

    for (start = 0; start <= end && end < n; sum -= arr[start++]){
        while(sum < x){
            sum += arr[++end];
        }

        result = min(result, end - start + 1);
    }

    if (result == x + 1) result = 0;

    cout << result << endl;

    return 0;
}
