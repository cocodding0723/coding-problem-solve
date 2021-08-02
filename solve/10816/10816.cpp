#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;
unordered_map<int, int>::iterator iter;

int N, input;

int main(){
    scanf("%d", &N);

    for (int i=0; i<N; i++){
        scanf("%d", &input);

        iter = m.find(input);
        if(iter == m.end()){
            m.insert(make_pair(input, 1));
        }
        else{
            iter->second++;
        }
    }

    scanf("%d", &N);

    for (int i=0; i<N; i++){
        scanf("%d", &input);

        iter = m.find(input);
        if(iter == m.end()){
            printf("0 ");
        }
        else{
            printf("%d ", iter->second);
        }
    }

    return 0;
}