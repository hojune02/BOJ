//백준 9095번: 1, 2, 3 더하기
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    int results[12];
    for (int i = 0; i <= 11; i++){
        results[i] = 0;
    }
    results[1] = 1;
    results[2] = 2;
    results[3] = 4;
    for (int i = 4; i <= 11; i++){
        results[i] = results[i-1] + results[i-2] + results[i-3];
    }

    while (T--){
        int target;
        cin >> target;
        cout << results[target] << "\n";
    }
    return 0;
}