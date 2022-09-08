#include <iostream>

using namespace std;

struct Person{
    int weight;
    int height;
    int rank = 1;
};

int main(){
    int n;
    Person *arr;

    cin >> n;

    arr = new Person[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i].weight >> arr[i].height;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            if (arr[i].weight > arr[j].weight && arr[i].height > arr[j].height) arr[j].rank++;
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i].rank << ' ';

    delete arr;

    return 0;
}