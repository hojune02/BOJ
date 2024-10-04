//백준 2869번: 달팽이는 올라가고 싶다
#include <iostream>
using namespace std;

int main(){
    int A, B, V;
    cin >> A >> B >> V;
    int count = 0;
    V -= A;
    count++;
    if (V % (A-B) == 0){
        count += (V / (A-B));
    } else{
        count += (V / (A-B) + 1);
    }
    cout << count;
}