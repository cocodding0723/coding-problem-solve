#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string str;
    char c;
    int digit, result = 0;

    cin >> str;

    for (int i = 0; i < str.length(); i++){
        c = str[i];
        digit = pow(16, str.length() - i - 1);
        if (c > 57){
            result += ((int)c - 55) * digit;
        }
        else{
            result += ((int)c - 48) * digit;
        }
    }

    cout << result;

    return 0;
}