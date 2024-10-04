//백준 15681번: 트리와 쿼리
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int maxN = 100000+1;

vector<int> connected[maxN];
int subtreeSize[maxN];

void dfs(int node, int parent){
    subtreeSize[node] = 1;
    for (int v : connected[node]){
        if (v != parent){
            dfs(v, node);
            subtreeSize[node] += subtreeSize[v];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, R, Q;
    cin >> N >> R >> Q;
    int a, b;
    for (int i = 0; i < N - 1; i++){
        cin >> a >> b;
        connected[a].push_back(b);
        connected[b].push_back(a);
    }
    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < connected[i].size(); j++){
    //         cout << connected[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    dfs(R, -1);

    int element;
    for (int i = 0; i < Q; i++){
        cin >> element;
        cout << subtreeSize[element] << "\n";
    }
    // cout << "\n";
    

    return 0;
}