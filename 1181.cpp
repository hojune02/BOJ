//백준 1181번: 단어 정렬
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

bool lengthCmp(string &a, string &b){
    return (a.length() < b.length());
}

int main(){
    int N;
    cin >> N;
    string arr[N];
    vector<vector<string>> strs(51);
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        arr[i] = str;
    }

    sort(arr, arr+N, lengthCmp);
    for (int i = 0; i<N; i++){
        if (find(strs[arr[i].length()].begin(), strs[arr[i].length()].end(), arr[i]) == strs[arr[i].length()].end()){
            strs[arr[i].length()].push_back(arr[i]);
        }
    }

    for (int i = 0; i < strs.size(); i++){
        if (strs[i].empty()) continue;
        sort(strs[i].begin(), strs[i].end());
    }
    for (int i = 0; i < strs.size(); i++){
        if (strs[i].empty()) continue;
        for (int j = 0; j < strs[i].size(); j++){
            cout << strs[i][j] << "\n";
        }

    }
    return 0;
}

//You can implement the part which strcmps the two strings 
//when they have the same length in the function outside of main()
//as well.