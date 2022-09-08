#include <iostream>

using namespace std;

int n, x;
int arr[100001];

int main(){
    int start, end, sum = 0, result;

    cin >> n >> x;

    result = x - 1;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (start = 0, end = 0; start <= end && end < n; start++){
        while (sum < x && end < n){
            sum += arr[end++];
        }
         cout << "start : " << start << " end : " << end << " sum : " << sum << endl;
        result = min(result, end - start);
        sum -= arr[start];
    }

    if (result == x + 1) result = 0;

    cout << result << endl;

    return 0;
}