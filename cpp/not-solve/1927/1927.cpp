// https://www.acmicpc.net/problem/1927
// 참고 필요 : https://jaimemin.tistory.com/1005
#include <iostream>

using namespace std;

int N;
int heap_size = 0;
int heap[100001];

void push(int n){
    int idx = ++heap_size;

	while ((idx != 1) && (n < heap[idx / 2])) {
		heap[idx] = heap[idx / 2];
		idx /= 2;
	}

	heap[idx] = n;
}

int pop(){
    if (heap_size == 0) return 0;

    int result = heap[1];
    int parent = 1, child = 2;

    heap[1] = heap[heap_size--];

    if (child > heap_size) return result;

    if (child + 1 > heap_size)
        child = heap[child] > heap[child + 1] ? child + 1 : child;

    while(child < heap_size && heap[parent] > heap[child]){
        swap(heap[parent], heap[child]);

        parent = child;
        child *= 2;

        if (child + 1 > heap_size)
            child = heap[child] > heap[child + 1] ? child + 1 : child;
    }
    
    return result;
}

int main(){
    int num;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> num;

        if (num == 0 && heap_size == 0){
            cout << 0 << endl;
        }
        else if (num == 0){
            cout << pop() << endl;
        }
        else{
            push(num);
        }
    }

    return 0;
}