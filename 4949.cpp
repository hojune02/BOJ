//백준 4949번: 균형잡힌 세상
#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;


bool balanced(string str){
    deque<char> temp;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '('){
            temp.push_back(str[i]);
        } else if (str[i] == '['){
            temp.push_back(str[i]);
        } else if (str[i] == ')'){
            if (!temp.empty() && temp.back() == '('){
                temp.pop_back();
            } else{
                temp.push_back(str[i]);
            }
        } else if (str[i] == ']'){
            if (!temp.empty() && temp.back() == '['){
                temp.pop_back();
            } else{
                temp.push_back(str[i]);
            }
        }
    }
    if (temp.empty()) return true;
    else return false;
        
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    vector<string> results;

    while (getline(cin, str)){
        if (str[0] == '.') break;
        
        if (balanced(str)){
            results.push_back("yes");
        }  else{
            results.push_back("no");
        }
    }

    for (int i = 0; i < results.size(); i++){
        cout << results[i] << "\n";
    }
    return 0;
}