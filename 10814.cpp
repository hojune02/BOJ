//백준 10814번: 나이순 정렬
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<pair<int, string>, int> &a, pair<pair<int, string>, int> &b){
    if (a.first.first < b.first.first){
        return true;
    } 
    if (a.first.first == b.first.first && a.second < b.second){
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    pair<pair<int, string>, int> arr[N];
    for (int i = 0; i < N; i++){
        int x;
        string str;
        cin >> x >> str;
        arr[i] = make_pair(make_pair(x, str), i);
    }
    sort(arr, arr+N, cmp);
    for (int i = 0; i < N; i++){
        cout << arr[i].first.first << " " << arr[i].first.second << "\n";
    }
    return 0;
}