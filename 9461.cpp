//백준 9461번: 파도반 수열
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    long long int results[101];
    for (int i = 0; i < 101; i++){
        results[i] = 0;
    }
    results[1] = 1;
    results[2] = 1;
    results[3] = 1;
    results[4] = 2;
    results[5] = 2;
    for (int i = 6; i <= 100; i++){
        results[i] = results[i-1] + results[i-5];
    }

    while (T--){
        int n;
        cin >> n;
        cout << results[n] << "\n";
    }

    return 0;

}