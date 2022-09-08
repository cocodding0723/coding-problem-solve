#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    string temp = "";
    int temp_count = 0;
    int stack[50];
    int stack_count = 0;

    cin >> input;

    for (int i = 0; i < input.size(); i++){
        if (input.at(i) == '-'){

        }
        else if (input.at(i) == '+'){
            
        }
        else{
            temp[temp_count++] = input.at(i);
        }
    }

    return 0;
}