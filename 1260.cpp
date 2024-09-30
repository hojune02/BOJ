//백준 1260번: DFS와 BFS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int v, vector<int> adj[], bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < adj[v].size(); i++) {
        int next = adj[v][i];
        if (!visited[next]) {
            dfs(next, adj, visited);
        }
    }
}

void bfs(int v, vector<int> adj[], bool visited[]) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int i = 0; i < adj[curr].size(); i++) {
            int next = adj[curr][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    vector<int> adj[N + 1];

    // Reading edges and building the graph
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a); // Since the graph is undirected
    }

    // Sorting adjacency lists
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // DFS
    bool visited_dfs[N + 1];
    dfs(V, adj, visited_dfs);
    cout << endl;

    // BFS
    bool visited_bfs[N + 1];
    bfs(V, adj, visited_bfs);
    cout << endl;

    return 0;
}
