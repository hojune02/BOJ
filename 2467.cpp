//백준 2467번: 용액
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int maxN = 100000;
long int elements[maxN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> elements[i];
    }
    
    sort(elements, elements + N);
    
    int left = 0, right = N - 1;
    long int min_sum = LONG_MAX;
    long int ans_left = elements[left], ans_right = elements[right];
    
    while (left < right) {
        long int current_sum = elements[left] + elements[right];
        
        if (abs(current_sum) < abs(min_sum)) {
            min_sum = current_sum;
            ans_left = elements[left];
            ans_right = elements[right];
        }
        
        if (current_sum < 0) {
            left++;
        } else if (current_sum > 0) {
            right--;
        } else {
            // Sum is zero, closest possible
            break;
        }
    }
    
    cout << ans_left << " " << ans_right << "\n";
    return 0;
}
