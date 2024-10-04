//백준 1966번: 프린터 큐
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int N;
    cin >> N;
    vector<int> results;
    for (int i = 0; i < N; i++){
        deque<int> importance;
        deque<pair<int, int>> eiPair;
        int n, target, imp;
        cin >> n >> target;
        for (int j = 0; j < n; j++){
            cin >> imp;
            importance.push_back(imp);
            eiPair.push_back(make_pair(j, imp));
        }
        int targetImp = importance[target];
        sort(importance.begin(), importance.end());
        int count = 0;
        while (!eiPair.empty() && !importance.empty() && !(eiPair.front().first == target && importance.back() == targetImp)){
            if (eiPair.front().second == importance.back()){
                eiPair.pop_front();
                importance.pop_back();
                count++;
            } else {
                eiPair.push_back(eiPair.front());
                eiPair.pop_front();
            }
        }
        results.push_back(count+1);
    }
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << "\n";
    }
    return 0;
}