// 문제 링크 : https://www.acmicpc.net/problem/2108
// 풀이 : 힙을 사용해서 푼다.

#include <iostream>

using namespace std;

class Heap{
private:
    int size = 0;
    int heap[500000] = { 0 };
public:
    void push(int&& number){
        int parent, child;

        heap[++size] = number;

        parent = size;
        child = size / 2;

        while(child > 1 && heap[parent] < heap[child]){
            parent = child;
            child = child / 2;
        }
    }

    int pop(){
        
    }
};

int main(){


    return 0;
}