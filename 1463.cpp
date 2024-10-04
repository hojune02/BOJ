//백준 1463번: 1로 만들기
/*
This might be similar to Dijkstra's Theorem..?
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int counts[1000001];
    counts[0] = 0;
    counts[1] = 0;
    counts[2] = 1;
    counts[3] = 1;
    for (int i = 4; i < 1000001; i++){
        counts[i] = 0;
    }

    for (int i = 4; i < 1000001; i++){
        vector<int> candidates;
        if (i % 3 == 0){
            candidates.push_back(counts[i/3] + 1);
        }
        if (i % 2 == 0){
            candidates.push_back(counts[i/2] + 1);
        }
        candidates.push_back(counts[i-1] + 1);
        int value = INT_MAX;
        for (int i = 0; i < candidates.size(); i++){
            value = min(candidates[i], value);
        }
        counts[i] = value;
    }

    cout << counts[N] << "\n";

    return 0;


}