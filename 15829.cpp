//백준 15829번: Hashing
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long int M = 1234567891;
    cin >> n;
    string target;
    cin >> target;
    long long int hashed = 0;
    long long int factor = 1;
    for (int i = 0; i < n; i++){
        long long int  number = (int) (target[i] - 'a' + 1);
        hashed = (hashed + number * factor) % M;
        factor *= 31;
        factor %= M;
    }
    cout << hashed;
    return 0;
}
//I neglected the mod M part first... Let's try again!