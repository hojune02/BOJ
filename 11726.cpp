//백준 11726번: 2xn 타일링
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    long long int results[N+1];
    results[0] = 0;
    results[1] = 1;
    results[2] = 2;
    for (int i = 3; i <= N; i++){
        results[i] = (results[i-1] % 10007 + results[i-2] % 10007) % 10007;
    }   
    cout << results[N] << "\n";
    return 0;
}