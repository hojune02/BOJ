#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M;
int maze[100][100];
int visited[100][100];
int dist[100][100];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    dist[a][b] = 1;

    while (!q.empty()){
        int current_x = q.front().first;
        int current_y = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = current_x + dx[i];
            int ny = current_y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                if (maze[nx][ny] == 1 && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                    dist[nx][ny] = dist[current_x][current_y] + 1;
                }
            }
        }
    }
}
int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        string line;
        cin >> line;
        for (int j = 0; j < M; j++){
            maze[i][j] = line[j] - '0';
        }
    }

    bfs(0, 0);

    cout << dist[N-1][M-1] << "\n";
    return 0;
}