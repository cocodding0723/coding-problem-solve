#include <iostream>

using namespace std;

struct POINT{
    int x, y;
};

class RECT{
private:
    POINT lb, rt;
public:
    RECT(POINT lb, POINT rb);
    RECT(int lx, int ly, int rx, int ry);
};

RECT rt[4];

int main(){
    for (int i = 0; i < 4; i++){
        
    }

    return 0;
}