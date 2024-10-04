//백준 2164번: 카드2
#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    deque<int> arr;
    for (int i = 1; i <= N; i++){
        arr.push_back(i);
    }
    while(arr.size() != 1){
        arr.pop_front();
        if (arr.size() == 1){
            break;
        }
        arr.push_back(arr.front());
        arr.pop_front();
    }
    cout << arr.front() << "\n";

    return 0;
}