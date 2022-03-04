#include <iostream>
#include <string>

using namespace std;

string input;

bool check(const string& str){
    int len = str.length();

    for (int i = 0; i < len / 2; i++){
        if (input[i] != input[len - i - 1]){
            return false;
        }
    }

    return true;
}

int main(){
    while(true){
        cin >> input;

        if (input == "0") break;

        int len = input.length();

        if (len == 1){
            cout << "yes" << endl;
            continue;
        }
        else{
            if (check(input)){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }

    return 0;
}