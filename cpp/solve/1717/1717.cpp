// ���� : https://blog.naver.com/ndb796/221230967614
#include <iostream>

using namespace std;

int arr[1000001];
int N, M;
int judge, a, b, parent, child;

void init(int size){
    for (int i = 0; i < size; i++){
        arr[i] = i;
    }
}

int get_parent(int x){
    if (arr[x] == x) return x;
    else return arr[x] = get_parent(arr[x]);        // ������ �θ� ����ؼ� ������
}

void make_union(int _a, int _b){
    _a = get_parent(_a);
    _b = get_parent(_b);
    if (_a > _b) arr[_b] = _a;
    else arr[_a] = _b;
}

// �� �ȵǴ��� ������ �𸣰���
// -> �ȵǴ� ���� : ������ �θ� �ٲ�� �θ� ��ü�� �� �ٲ�� ���� �ƴ�
// void make_union(int _a, int _b){
//     if (arr[_a] > arr[_b]){
//         arr[_a] = arr[_b];
//     }
//     else{
//         arr[_b] = arr[_a];
//     }
// }

bool find_union(int _a, int _b){
    return get_parent(_a) == get_parent(_b);
}

int main(){
    scanf("%d %d", &N, &M);

    init(N + 1);

    for (int i = 0; i < M; i++){
        scanf("%d %d %d", &judge, &a, &b);
        if (judge == 0){
            make_union(a, b);
        }
        else if (judge == 1){
            if (find_union(a, b)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }

    return 0;
}