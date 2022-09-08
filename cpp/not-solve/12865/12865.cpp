#include <iostream>

using namespace std;

struct PACK{
    int weight;
    int value;
};

int N, K;
int highestValue;
PACK packs[101];

int main(){
    cin >> N >> K;
    cin >> packs[0].weight >> packs[0].value;

    if (packs[0].weight < K){
        highestValue = packs[0].value;
    }
    else{
        highestValue = 0;
    }

    for (int i = 1; i < N; i++){
        cin >> packs[i].weight >> packs[i].value;

        if (packs[i].weight + packs[i - 1].weight <= K && packs[i].value < packs[i].value + packs[i - 1].value){
            packs[i].weight += packs[i - 1].weight;
            packs[i].value += packs[i - 1].value;
        }

        highestValue = max(highestValue, packs[i].value);
    }

    cout << highestValue;

    return 0;
}