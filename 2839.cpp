//백준 2839번: 설탕 배달
#include <iostream>
using namespace std;
int results[5000+1];

int countBags(int n){
    if (n==1) return -1;
    if (n==2) return -1;
    if (n==3) return 1;
    if (n==4) return -1;
    if (n==5) return 1;
    if (n==7) return -1;
    int rem5 = n % 5;
    if (rem5 == 0){
        return n / 5;
    } else{
        if (rem5 == 4) return (n/5 + 2);
        else if (rem5 == 3) return (n/5 + 1);ß
        else if (rem5 == 2) return (n/5 + 2);
        else return (n/5 + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << countBags(n) << "\n";


    return 0;
}