//백준 2579번: 계단 오르기
#include <iostream>
#include <cmath>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int stairs[N+1];
    for (int i = 1; i <= N; i++){
        int elem;
        cin >> elem;
        stairs[i] = elem;
    }
    int results[N+1];
    for (int i = 0; i < N+1; i++){
        results[i] = 0;
    }
    
    results[1] = stairs[1];
    results[2] = stairs[2] + stairs[1];
    results[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
    for (int i = 4; i <= N; i++){
        int cand1 = results[i-2] + stairs[i];
        int cand2 = results[i-3] + stairs[i-1] + stairs[i];
        results[i] = max(cand1, cand2);
    }


    cout << results[N] << "\n";

    return 0;
}