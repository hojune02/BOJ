//백준 10773번: 제로
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    deque<int> arr;
    int N; cin >> N;

    while (N--){
        int elem;
        cin >> elem;
        if (!arr.empty() && elem == 0){
            arr.pop_back();
        } else{
            arr.push_back(elem);
        }
    }
    int sum = 0;
    while (!arr.empty()){
        sum += arr.front();
        arr.pop_front();
    }
    cout << sum;

    return 0;
}