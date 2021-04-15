#include <iostream>

using namespace std;

int N, min_oil, city, minimum;
int dist[100001];
long long result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    minimum = 1000000001;

    for (int i = 0; i < N - 1; i++) cin >> dist[i];

    cin >> min_oil;
    result = min_oil * dist[0];

    for (int i = 1; i < N - 1; i++) {
        cin >> city;
        min_oil = min(min_oil, city);
        result += dist[i] * min_oil;
    }

    cout << result;

    return 0;
}