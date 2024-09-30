//백준 30802번: 웰컴 키트
#include <iostream>
using namespace std;

int tshirtNum(int num, int bundle){
    int rem = num % bundle;
    int quotient = num / bundle;
    if (rem > 0){
        return quotient + 1;
    } else{
        return quotient;
    }
}

int main(){
    int N, size, T, P;
    cin >> N;
    int sizes[6];
    for (int i = 0; i < 6; i++){
        cin >> size;
        sizes[i] = size;
    }
    cin >> T >> P;
    int Tbundle = 0;
    for (int i = 0; i < 6; i++){
        Tbundle += tshirtNum(sizes[i], T);
    }
    cout << Tbundle << "\n";
    cout << (N / P) << " " << (N % P) << "\n";

    return 0;
}