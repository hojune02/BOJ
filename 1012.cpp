//백준 1012번: 유기농 배추
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void solve(int M, int N, vector<vector<bool>> &field, int x, int y, int &count){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    deque<pair<int, int>> cabbage;
    if (field[x][y]){
        cabbage.push_back(make_pair(x, y));
        field[x][y] = false;
    }
    if (!cabbage.empty()){
        count++;
    }
    while(!cabbage.empty()){
        pair<int, int>cab = cabbage.front();
        cabbage.pop_front();

        for (int i = 0; i < 4; i++){
            int nx = cab.first + dx[i];
            int ny = cab.second + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && field[nx][ny] == true){
                field[nx][ny] = false;
                cabbage.push_back(make_pair(nx, ny));
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, M, N, K;
    cin >> T;
    vector<int> results;
    while (T--){
        cin >> M >> N >> K;
        vector<vector<bool>> field(M, vector<bool>(N));
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                field[i].push_back(false);
            }
        }
        for (int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            field[x][y] = true;
        }
        // for (int i = 0; i < M; i++){
        //     for (int j = 0; j < N; j++){
        //         cout << field[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        int count = 0;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                solve(M, N, field, i, j, count);
            }
        }
        
        results.push_back(count);
    }
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << "\n";
    }

    return 0;
}