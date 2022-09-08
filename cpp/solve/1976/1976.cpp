#include <iostream>

using namespace std;

int cityCount, planCityCount, isLinked;
int parents[201];

int find_parent(int x){
    if (parents[x] == x) return x;
    return parents[x] = find_parent(parents[x]);
}

void set_union(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if (a > b) parents[a] = b;
    else parents[b] = a;
}

bool is_union(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    return a == b;
}

int main(){
    for (int i = 0; i < 201; i++)
        parents[i] = i;
    
    cin >> cityCount >> planCityCount;

    for (int i = 1; i <= cityCount; i++){
        for (int j = 1; j <= cityCount; j++){
            cin >> isLinked;

            if (isLinked){
                set_union(i, j);
            }
        }
    }

    int conectionCount = 1;
    int prevCity, currentCity;

    cin >> prevCity;

    for (int i = 1; i < planCityCount; i++){
        cin >> currentCity;
        if (::is_union(prevCity, currentCity)){
            conectionCount++;
            prevCity = currentCity;
        }
    }

    if (conectionCount == planCityCount) cout << "YES";
    else cout << "NO";

    return 0;
}