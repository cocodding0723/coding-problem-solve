#include <iostream>
#include <math.h>

using namespace std;

char blocks[51][51];

int RedrawBlockCount(int startX, int startY){
    int black_redrawCount = 0, white_redrawCount = 0;

    // 0,0이 검정일때    
    for (int y = 0; y < 8; y++){
        for (int x = 0; x < 8; x++){
            if (y % 2 == 0){
                if (x % 2 == 0 && blocks[startY + y][startX + x] != 'B') 
                    black_redrawCount++;
                if (x % 2 == 1 && blocks[startY + y][startX + x] != 'W') 
                    black_redrawCount++;
            }
            else{
                if (x % 2 == 1 && blocks[startY + y][startX + x] != 'B') 
                    black_redrawCount++;
                if (x % 2 == 0 && blocks[startY + y][startX + x] != 'W') 
                    black_redrawCount++;
            }
        }
    }

    for (int y = 0; y < 8; y++){
        for (int x = 0; x < 8; x++){
            if (y % 2 == 0){
                if (x % 2 == 0 && blocks[startY + y][startX + x] != 'W') 
                    white_redrawCount++;
                if (x % 2 == 1 && blocks[startY + y][startX + x] != 'B') 
                    white_redrawCount++;
            }
            else{
                if (x % 2 == 1 && blocks[startY + y][startX + x] != 'W') 
                    white_redrawCount++;
                if (x % 2 == 0 && blocks[startY + y][startX + x] != 'B') 
                    white_redrawCount++;
            }
        }
    }

    return min(black_redrawCount, white_redrawCount);
}

int main(){
    int N, M;
    int min = 9999999;
    int drawCount;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> blocks[i][j];

    int cul = N - 8 + 1;
    int row = M - 8 + 1;

    for (int y = 0; y < cul; y++){
        for (int x = 0; x < row; x++){
            drawCount = RedrawBlockCount(x, y);
            if (drawCount < min) min = drawCount;
        }
    }

    cout << min << endl;

    return 0;
}