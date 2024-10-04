//백준 11047번: 동전 0
#include <iostream>
#include <deque>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, target;
    cin >> N >> target;
    int notes[N];
    for (int i = 0 ; i < N; i++){
        int elem;
        cin >> elem;
        notes[i] = elem;
    }

    int count = 0;
    for (int i = N-1; i >= 0; i--){
        int a = target/notes[i];
        int rem = target % notes[i];
        count += a;
        target = rem;
    }
    cout << count << "\n";


    return 0;
}