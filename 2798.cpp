//백준 2798번: 블랙잭
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main(){
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        arr[i] = elem;
    }
    int current = INT_MIN;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                int temp;
                if ((temp = arr[i] + arr[j] + arr[k]) <= target){
                    current = max(temp, current);
                }
            }
        }
    }
    cout << current;
    return 0;
}