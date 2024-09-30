//백준 2239: 스도쿠
#include <iostream>
#include <vector>
using namespace std;
int sudoku[10][10];
vector<pair<int, int>> zeros;

bool isPossible(int x, int y, int target){
    for (int i = 1; i <= 9; i++){
        if (sudoku[x][i] == target && i != y) return false;

        if (sudoku[i][y] == target && i != x) return false;

        int nx = (x-1)/3*3 + 1 + (i-1)/3;
        int ny = (y-1)/3*3 + 1 + (i-1)%3;
        if (sudoku[nx][ny] == target && !(x == nx && y == ny)) return false;
    }
    return true;
}

void solve(int index){
    if (index >= zeros.size()){
        for (int i = 1; i <= 9; i++){
            for (int j = 1; j <= 9; j++){
                cout << sudoku[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    int x = zeros[index].first;
    int y = zeros[index].second;
    for (int i = 1; i <= 9; i++){
        if (isPossible(x, y, i)){
            sudoku[x][y] = i;
            solve(index+1);
            sudoku[x][y] = 0;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i = 1; i <= 9; i++){
        char element[10]; /*zsh: abort error when using element[9].
        This is because the null character must be taken into accout.*/
        cin >> element;
        for (int j = 1; j <= 9; j++){
            int add = element[j-1] - '0';
            if (add == 0){
                zeros.push_back(make_pair(i, j));
            }
            sudoku[i][j] = add;
        }
    }

    solve(0);

}