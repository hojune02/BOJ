//백준 1259번: 팰린드롬수
//Using a queue might be an idea...
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
using namespace std;
vector<int> result;
deque<char> temp;

void isPalin(string str){
    int limit = floor((float)str.length()/2);
    for (int i = 0; i < limit; i++){
        temp.push_back(str[i]);
    }
    if (str.length() % 2 == 0){
        for (int i = limit; i < str.length(); i++){
            if (temp.back() == str[i]){
                temp.pop_back();
            } else{
                continue;
            }
        }
    } else{
        for (int i = limit + 1; i < str.length(); i++){
            if (temp.back() == str[i]){
                temp.pop_back();
            } else{
                continue;
            }
        }
    }
    if (temp.empty()){
        result.push_back(1);
    } else{
        result.push_back(0); 
    }
    while (!temp.empty()){
        temp.pop_front();
    }
}

int main(){
    string str = "\0";
    while (str != "0"){
        cin >> str;
        if (str != "0"){
            isPalin(str);
        }
    }
    for (int i = 0; i < result.size(); i++){
        if (result[i]){
            cout << "yes\n";
        } else{
            cout << "no\n";
        }
    }
    return 0;
}