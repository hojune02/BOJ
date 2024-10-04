//백준 2606번: 바이러스
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    cin >> N >> E;
    vector<int> edge[N+1];
    for (int i = 0; i < E; i++){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int visited[N+1];
    for (int i = 0; i <= N; i++){
        visited[i] = 0;
    }
    deque<int> q;
    q.push_back(1);
    int count = 0;
    while(!q.empty()){
        int elem = q.front();
        q.pop_front();
        visited[elem] = 1;
        for (int i = 0; i < edge[elem].size(); i++){
            if (!visited[edge[elem][i]]){
                q.push_back(edge[elem][i]);
                visited[edge[elem][i]] = 1;
            }
        }
        count++;
    }
    cout << count - 1 << "\n";
    return 0;
}