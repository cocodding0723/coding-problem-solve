#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

#define P pair<int, int>

int n, mini = 4001, maxi = -4001, middle, most;
int arr[500001];
map<int, int> s;
map<int, int>::iterator iter;
double avg;

bool compare_most(const P& a, const P& b){
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

bool compare(const int& a, const int&b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];

        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);

        avg += arr[i];

        iter = s.find(arr[i]);

        if (iter == s.end()) s.insert(make_pair(arr[i], 1));
        else{
            iter->second++;
        }
    }

    sort(arr, arr + n, compare);

    vector<P> vec(s.begin(), s.end());
    sort(vec.begin(), vec.end(), compare_most);

    most = vec.size() > 1 ? (vec[0].second == vec[1].second ? vec[1].first : vec[0].first) : vec[0].first;

    cout << round(avg / n) << endl;
    cout << arr[n / 2] << endl;
    cout << most << endl;
    cout << maxi - mini;

    return 0;
}