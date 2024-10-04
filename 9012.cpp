//백준 9012번: 괄호
#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

bool solve(string str){
    deque<char> temp;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '('){
            temp.push_back('(');
        } else if (str[i] == ')'){
            if (!temp.empty() && temp.back() == '('){
                temp.pop_back();
            } else{
                temp.push_back(')');
            }
        } else{
            continue;
        }
    }
    if (temp.empty()) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> results;
    while (N--){
        string str;
        cin >> str;
        if (solve(str)) results.push_back("YES");
        else results.push_back("NO");
    }
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << "\n";
    }


    return 0;
}