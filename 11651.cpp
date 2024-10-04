//백준 11651번: 좌표 정렬하기 2
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if (a.second < b.second){
        return true;
    }
    if (a.second == b.second && a.first < b.first){
        return true;
    
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    pair<int, int> arr[N];
    for (int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }
    sort(arr, arr + N, cmp);
    for (int i = 0; i < N; i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;

}