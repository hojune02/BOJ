//백준 2231번: 분해합
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int digitSum = 0;
        int original = i;
        while (i > 0){
            digitSum += i % 10;
            i /= 10;
        }
        int result = original + digitSum;
        if (result == n){
            cout << original << "\n";
            return 0;
        }
        i = original;  
    }
    cout << 0 << "\n";
    return 0;
}