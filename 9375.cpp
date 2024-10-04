//백준 9375번: 패션왕 신해빈
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    map<string, vector<string>> type_to_elem;
    while (T--){
        int N;
        cin >> N;
        for (int i = 0; i < N; i++){
            string item, type;
            cin >> item >> type;
            
            type_to_elem[type].push_back(item);

        }
        vector<int> results;
        for (auto it = type_to_elem.begin(); it != type_to_elem.end(); it++){
            results.push_back(it->second.size());
        } 
        int product = 1;  
        for (int i = 0; i < results.size(); i++){
            product *= (results[i]+1);
        }
        cout << product - 1 << "\n";
        type_to_elem.clear();
    }

    return 0;
}