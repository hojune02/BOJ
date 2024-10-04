//백준 11050번: 이항 계수 1
#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int rem = N - K;
    int res1 = 1; int res2 = 1; int res3 = 1;

    for (int i = 1; i <= N; i++){
        res1 *= i;
    }
    for (int i = 1; i <= K; i++){
        res2 *= i;
    }
    for (int i = 1; i <= rem; i++){
        res3 *= i;
    }
    cout << (res1 / (res2 * res3));
    return 0;
}