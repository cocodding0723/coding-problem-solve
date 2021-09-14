#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int start, end, simmilar = INT32_MAX, a, b;

    cin >> n;

    end = n - 1;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(&arr[0], &arr[n]);

    for (start = 0; start < end; start++){
        for (; abs(0 - (arr[start] + arr[end])) > simmilar && end > -1; end--);

        if (abs(0 - (arr[start] + arr[end])) <= simmilar){
            simmilar = abs(arr[start] + arr[end]);
            a = arr[start];
            b = arr[end];
        }
    }

    if (a > b) swap(a, b);

    cout << a << ' ' << b;

    return 0;
}