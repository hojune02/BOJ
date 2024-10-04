//백준 10451번: 순열 사이클
#include <iostream>
#include <stack>
using namespace std;

int sequence[1001];
int visited[1001];
int T, N;
int count_cycle = 0;
int count_cycle_list[1000];

void dfs(int a){
    visited[a] = 1;
    stack<int> s;
    s.push(a);
    while(!s.empty()){
        int next = sequence[s.top()];
        s.pop();
        if (!visited[next]){
            visited[next] = 1;
            s.push(next);
        } else{
            count_cycle++;
        }
    }
}

int main(){
    cin >> T;
    int original_t = T;
    int x = 0;
    while (T--){
        cin >> N;
        int element;
        for (int i = 1; i <= N; i++){
            cin >> element;
            sequence[i] = element;
        }

        for (int i = 1; i <= N; i++){
            if (!visited[i]){
                dfs(i);
            }
        }
        count_cycle_list[x] = count_cycle;
        
        for (int i = 1; i <= N; i++){
            sequence[i] = 0;
            visited[i] = 0;
        }
        count_cycle = 0;
        x++;
    }
    for (int i = 0; i < original_t; i++){
        cout << count_cycle_list[i] << "\n";
    }
    return 0;
}