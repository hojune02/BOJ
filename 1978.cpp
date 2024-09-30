//백준 1978번: 소수 찾기
#include <iostream>
using namespace std;

int isPrime(int x){
    if (x==1) return 0;
    if (x==2) return 1;
    for (int i = 2; i < x; i++){
        if (x % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++){
        int elem;
        cin >> elem;
        arr[i] = elem;
    }
    int count = 0;
    for (int i = 0; i < N; i++){
        count += isPrime(arr[i]);
    }
    cout << count;
    return 0;
}