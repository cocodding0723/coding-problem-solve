#include <iostream>
#include <vector>

using namespace std;

struct person_info{
    int hegiht;
    int weight;
    int number;
};

typedef struct person_info* PERSON;

struct PEOPLE{
    vector<PERSON> people;
    int max_height = 0;
    int max_weight = 0;
};

person_info person_infos[52];
PEOPLE people_group[52];
int N, w, h;

int main(){
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> w >> h;

        
    }
}