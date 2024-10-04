//백준 1018번: 체스판 다시 칠하기
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

char referenceWhite[8][8] = {
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};

char referenceBlack[8][8] = {
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
};


int main(){
    int N, M;
    cin >> N >> M;
    char board[N][M];
    for (int i = 0; i < N; i++){
        string input;
        cin >> input;
        for (int j = 0; j < M; j++){
            board[i][j] = input[j];
        }
    }
    int xOffset = N - 8;
    int yOffset = M - 8;
    int sizeOff = (xOffset+1) * (yOffset+1);
    pair<int, int> offsetList[sizeOff];
    int temp = 0;
    for (int i = 0; i <= xOffset; i++){
        for (int j = 0; j <= yOffset; j++){
            offsetList[temp] = make_pair(i, j);
            temp++;
        }
    }

    int count = INT_MAX;
    int counts[sizeOff];

    for (int i = 0; i < sizeOff; i++){
        int first = offsetList[i].first;
        int second = offsetList[i].second;
        char reference[8][8];
        char fromRefer[8][8];
        for (int x = first; x < first + 8; x++){
            for (int y = second; y < second + 8; y++){
                reference[x-first][y-second] = board[x][y];
            }
        }
        int count1 = 0;
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (reference[i][j] != referenceWhite[i][j]){
                    count1++;
                }
            }
        }
        count = min(count1, count);
        int count2 = 0;
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (reference[i][j] != referenceBlack[i][j]){
                    count2++;
                }
            }
        }
        count = min(count2, count);
    }

    cout << count << "\n";

    return 0;
}