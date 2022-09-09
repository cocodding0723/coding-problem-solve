#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;
vector<int> v;

int totalCount = 0;

void push(int item){
    totalCount++;

    if (totalCount == 1){
        max_heap.push(item);
        return;
    }

    if (item > max_heap.top()){
        min_heap.push(item);
    }
    else{
        max_heap.push(item);
    }

    if (totalCount % 2 == 0){
        if (max_heap.size() > min_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() > max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
}

int getMiddle(){
    if (totalCount % 2 == 1)
        return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
    return max_heap.top();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    int input;

    cin >> t;

    for (int i = 0; i < t; i++){
        cin >> input;
        push(input);
        cout << getMiddle() << '\n';
    }

    return 0;
}