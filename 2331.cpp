//백준 2331번: 반복수열
#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>
#include <unordered_map> // 추가
using namespace std;

int A, P;
unordered_map<int, int> visited; // 변경
int count_num = 0;

int dfs(int a){
    stack<int> s;
    s.push(a);
    visited[a] = 1;
    int next = 0;
    while (true){
        int current = s.top();
        int floor_num = floor(log10(current));
        next = 0;
        for (int i = 0; i <= floor_num; i++){
            int rem = current % 10;
            next += pow(rem, P);
            current /= 10;
        }
        if (visited[next] == 1){
            break; // 루프 종료
        }

        s.push(next);
        visited[next] = 1;
    }

    int target = next;

    while(!s.empty() && s.top() != target){
        s.pop();
    }

    while (!s.empty()){
        s.pop();
        count_num++;
    }
    
    return count_num-1;
}

int main(){
    cin >> A >> P;
    cout << dfs(A) << "\n";
    return 0;
}
