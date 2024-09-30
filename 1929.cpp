//백준 1929번: 소수 구하기
#include <iostream>
using namespace std;
const int number = 1000000;
int result[number+1];

void isPrimeSieve(int x, int y){
/*
Using Eratosthenes' Sieve
*/
    for (int i = 2; i <= y; i++){
        if (result[i] == 0) continue;
        for (int j = 2*i; j <= number; j += i){
            result[j] = 0;
        }
    }
    for (int i = x; i <= y; i++){
        if (result[i] != 0){
            cout << result[i] << "\n";
        }
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < (number + 1); i++){
        result[i] = i;
    }
    result[1] = 0;
    isPrimeSieve(a, b);
    return 0;
}