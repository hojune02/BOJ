//백준 2292번: 벌집
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 1;
    n--;
    for (int i = 1; n > 0; i++){
        n -= i * 6;
        count++;
    }
    cout << count << "\n";
    return 0;
}