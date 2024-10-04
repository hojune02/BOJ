//백준 2108번: 통계학
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr;
    int freq[8000+1];
    for (int i = 0; i < 8001; i++){
        freq[i] = 0;
    }

    for (int i = 0; i < N; i++){
        int elem;
        cin >> elem;
        arr.push_back(elem);
        freq[elem + 4000] += 1;
    }
    sort(arr.begin(), arr.end());

    double sum = 0;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }
    int average = round(sum / N);
    int mid = (N-1)/2;
    int median = arr[mid];

    // for (int i = 0; i < N; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    //cout << arr.size() << " " << arr[0] << "\n";
    int range = arr[N-1] - arr[0];

    int max = -1;
    for (int i = 0; i < 8001; i++){
        if (freq[i] > max){
            max = freq[i];
        }
    }
    vector<int> mode_candidates;
    for (int i = 0; i < 8001; i++){
        if (freq[i] == max){
            mode_candidates.push_back(i);
        }
    }
    int mode;
    if (mode_candidates.size() > 1){
        mode = mode_candidates[1];
    } else {
        mode = mode_candidates[0];
    }

    cout << average << "\n";
    cout << median << "\n";
    cout << mode - 4000 << "\n";
    cout << range << "\n";

    return 0;
}