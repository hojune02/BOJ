// 백준 1806번: 부분합
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

long int solve(vector<long int> numbers, long int target){
    long int i = 0;
    long int j = 0;
    long int sum = numbers[0];
    long int minSize = LLONG_MAX;
    while(i <= j && j <= numbers.size()-1){
        if (sum < target){
            j++;
            sum += numbers[j];
        } else{
            minSize = min(minSize, j-i+1);
            sum -= numbers[i];
            i++;
        }
    }
    if (minSize == LLONG_MAX) return 0;
    return minSize;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long int N, S;
    cin >> N >> S;
    vector<long int> numbers(N, 0);
    for(long int i = 0; i < N; i++){
        long int element;
        cin >> element;
        numbers[i] = element;
    }

    cout << solve(numbers, S) << "\n";

    return 0;
    
}