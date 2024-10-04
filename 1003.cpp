//백준 1003번: 피보나치 함수
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> fibonacci_calls(int n){
    if (n == 0) return make_pair(1, 0);
    if (n == 1) return make_pair(0, 1);
    int first = fibonacci_calls(n-1).first + fibonacci_calls(n-2).first;
    int second = fibonacci_calls(n-1).second + fibonacci_calls(n-2).second;
    return make_pair(first, second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    pair<int, int> results[41];
    results[0] = make_pair(1, 0);
    results[1] = make_pair(0, 1);
    for (int i = 2; i < 41; i++){
        results[i].first = results[i-1].first + results[i-2].first;
        results[i].second = results[i-1].second + results[i-2].second;
    }
    while (T--){
        int target;
        cin >> target;
        cout << results[target].first << " " << results[target].second << "\n";
    }

    return 0;
}