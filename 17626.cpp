#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main(){
    int N = 50000;
    int results[N+1];
    for (int i = 0; i <= N; i++){
        results[i] = 0;
    }
    for (long long int i = 1; i <= N; i++){
        if (i == 1){
            results[i] = 1;
        } 
        if (results[i] == 1){
            continue;
        } else{
            int minimum = INT_MAX;
            for (long long int j = 1; j*j <= i; j++){
                minimum = min(results[i - j*j] + 1, minimum);
            }
            results[i] = minimum;
            if (i*i <= N){
                results[i*i] = 1;
            }
        }
    }
    int input;
    cin >> input;
    cout << results[input] << "\n";
    return 0;
}