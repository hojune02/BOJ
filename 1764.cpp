//백준 1764번: 듣보잡
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, string> see;
    unordered_map<string, int> hear;
    
    int N, M;
    cin >> N >> M;
    vector<string> result;
    for (int i = 0; i < N; i++){
        string name;
        cin >> name;
        see[i] = name;
    }
    for (int i = 0; i < M; i++){
        string name;
        cin >> name;
        hear[name] = i;
    }
    for (int i = 0; i < N; i++){
        string target = see[i];
        auto p = hear.find(target);
        if (p != hear.end()){
            result.push_back(target);
        } else{
            continue;
        }
    }
    cout << result.size() << "\n";
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << "\n";
    }

    return 0;
}