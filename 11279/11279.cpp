// Âü°í : https://hsho.tistory.com/23
#include <iostream>

using namespace std;

int heap[100001];
int heap_size = 0, input_value, N;

void push(int data){
    int insert_pos = ++heap_size;
    while(insert_pos != 1 && data > heap[insert_pos / 2]){
        heap[insert_pos] = heap[insert_pos / 2];
        insert_pos /= 2;
    }

    heap[insert_pos] = data;
}

int pop(){
    if (heap_size == 0) return 0;

    int result = heap[1];
    heap[1] = heap[heap_size--];

    int parent = 1;
    int child;

    while(heap[parent] < heap[child] && child <= heap_size){
        child *= 2;

        if (heap[child] < heap[child + 1] && child + 1 <= heap_size){
            child++;
        }

        int tmp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = tmp;

        parent = child;
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i=0; i<N; i++){
        cin >> input_value;

        if (input_value == 0) {
            cout << pop() << endl;
        }
        else{
            push(input_value);
        }
    }
}
