//백준 10828번: 스택
#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int i;
    int N;
    cin >> N;
    deque<int> arr;
    vector<int> outputs;
    while (N--){
        cin >> str;
        if (str == "push"){
            cin >> i;
            arr.push_back(i);
        } else if (str == "pop"){
            if (!arr.empty()){
                outputs.push_back(arr.back()); arr.pop_back();
            } else {
                outputs.push_back(-1);
            }
        } else if (str == "size"){
            outputs.push_back(arr.size());
        } else if (str == "empty"){
            if (arr.empty()) outputs.push_back(1);
            else outputs.push_back(0);
        } else{ // top
            if (arr.empty()) outputs.push_back(-1);
            else outputs.push_back(arr.back());
        }
    }
    for (int i = 0; i < outputs.size(); i++){
        cout << outputs[i] << "\n";
    }
    return 0;
}