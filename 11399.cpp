//백준 11399번: ATM
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int times[N];
    for (int i = 0; i < N; i++){
        int elem;
        cin >> elem;
        times[i] = elem;
    }
    sort(times, times + N);
    int sums[N];
    for (int i = 0; i < N; i++){
        if (i==0){
            sums[i] = times[i];
        } else{
            sums[i] = sums[i-1] + times[i];
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += sums[i];
    }
    cout << sum;

    return 0;
}