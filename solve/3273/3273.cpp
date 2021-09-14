#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x, end, result = 0;
    cin >> n;

    end = n - 1;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    cin >> x;

    sort(&arr[0], &arr[n]);

    for (int start = 0; start < end; start++){
        while(arr[start] + arr[end] > x && end > -1){
            end--;
        }

        if (arr[start] + arr[end] == x){
            result++;
            end--;
        }
    }

    cout << result << endl;

    return 0;
}