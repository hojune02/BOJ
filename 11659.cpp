//백준 11659번: 구간 합 구하기 4
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int results[100000+1];
    for (int i = 0; i < 100000+1; i++){
        results[0] = 0;
    }
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        int elem;
        cin >> elem;
        if (i==1) results[i] = elem;
        else{
            results[i] = elem + results[i-1];
        }
    }
    while (M--){
        int x, y;
        cin >> x >> y;
        cout << results[y] - results[x-1]  << "\n";
    }

    return 0;
}