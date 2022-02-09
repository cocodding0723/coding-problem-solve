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

    while(start <= end && end < n){
        if (sum < x){
            sum += arr[++end];
        }
        else{
            result = min(result, end - start + 1);
            sum -= arr[start++];
        }
        cout << "start : " << start << " end : " << end << " sum : " << sum << endl;
    }

    if (result == x + 1) result = 0;

    cout << result << endl;

    return 0;
}
