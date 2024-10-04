//백준 1654번: 랜선 자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;
    vector<uint> arr;
    for (int i = 0; i < K; i++){
        unsigned int elem;
        cin >> elem;

        arr.push_back(elem);
    }
    sort(arr.begin(), arr.end());

    uint total = 0;
    unsigned int target = 0;
    unsigned int start = 1;
    unsigned int end = arr[K-1];

    while (end >= start){
        uint temp = (start+end)/2;

        for (int i = 0; i < K; i++){
            uint count = arr[i] / temp;
            total += count;
        }
        if (total >= N){
            target = temp;
            start = temp + 1;


        } else {
            end = temp-1;

        }
        total = 0;
    }
    cout << target << "\n";



    return 0;
}

//I neglected the possible overflow.