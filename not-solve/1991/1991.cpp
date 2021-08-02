#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct NODE{
    char value;
    char left;
    char right;
};

string result;
NODE tree[28];

void pre_order(NODE cur){
    if (cur.value == 0) return;

    result.push_back(cur.value);
    if (cur.left != ' ') pre_order(tree[cur.left - 65]);
    if (cur.right != ' ') pre_order(tree[cur.right - 65]);
}

void in_order(NODE cur){
    if (cur.value == 0) return;

    if (cur.left != ' ') in_order(tree[cur.left - 65]);
    result.push_back(cur.value);
    if (cur.right != ' ') in_order(tree[cur.right - 65]);
}

void post_order(NODE cur){
    if (cur.value == 0) return;

    if (cur.left != ' ') post_order(tree[cur.left - 65]);
    if (cur.right != ' ') post_order(tree[cur.right - 65]);
    result.push_back(cur.value);
}

int main(){
    int N;

    cin >> N;

    for (int i = 0; i < N; i++){
        NODE node;

        cin >> node.value >> node.left >> node.right;

        if (node.left == '.') node.left = 0;
        if (node.right == '.') node.right = 0;

        tree[i] = node;
    }

    for (int i = 0; i < N; i++){
        cout << tree[i].value << ' ' << tree[i].left << ' ' << tree[i].right << endl;
    }

    // pre_order(tree[0]);
    // cout << result << endl;

    // result.clear();

    // in_order(tree[0]);
    // cout << result << endl;

    // result.clear();

    // post_order(tree[0]);
    // cout << result << endl;

    // result.clear();

    return 0;
}