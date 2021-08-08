#include <iostream>

using namespace std;

int N, result;
int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> arr[0];

    result = arr[0];

    for (int i = 1; i < N; i++){
        cin >> arr[i];

        arr[i] = max(arr[i], arr[i] + arr[i - 1]);

        result = max(arr[i], result);
    }

    cout << result;

    return 0;
}