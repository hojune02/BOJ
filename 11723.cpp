//백준 11723번: 집합
//Bittracking
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    uint target = 0;
    vector<bool> results;
    while (N--){
        string str;
        uint x;
        cin >> str;

        if (str == "add"){
            cin >> x;
            if (!(target & 1 << (x-1))){
                target |= 1 << (x-1);
            }
        } else if (str == "remove"){
            cin >> x;
            if ((target & 1 << (x-1))){
                target &= (2097151 - (1 << (x-1)));
            }
            
        } else if (str == "check"){
            cin >> x;
            bool isSet = (target & (1 << (x-1)));
            if (isSet){
                results.push_back(true);
            } else {
                results.push_back(false);
            }
        } else if (str == "toggle"){
            cin >> x;
            if (target & 1 << (x-1)){ //set
                target &= (2097151 - (1 << (x-1)));
            } else{
                target |= 1 << (x-1);
            }
        } else if (str == "all"){
            target |= 2097151;
        } else {
            target &= 0;
        }
    }
    for (int i = 0; i < results.size(); i++){
        if (results[i]){
            cout << "1\n";
        } else{
            cout << "0\n";
        }
    }
    


    return 0;
}