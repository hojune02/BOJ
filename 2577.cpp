//백준 2577번: 숫자의 개수
#include <iostream>
using namespace std;

int main(){
    int counts[10];
    for (int i = 0; i <= 9; i++){
        counts[i] = 0;
    }
    int a, b, c;
    cin >> a >> b >> c;
    int product = a * b * c;
    while (product > 0){
        int rem = product % 10;
        counts[rem] += 1;
        product /= 10;
    }
    for (int i = 0; i <= 9; i++){
        cout << counts[i] << "\n";
    }
    return 0;
}