//백준 1620번: 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    
    vector<string> num_to_name;

    unordered_map<string, int> name_to_num;

    int count = 1;
    for (int i = 0; i < N; i++){
        string name;
        cin >> name;
        num_to_name.push_back(name);
        name_to_num[name] = count;
        count++;
    }
    for (int i = 0; i < M; i++){
        string input;
        cin >> input;
        if (isdigit(input[0])){
            int digit = stoi(input);
            cout << num_to_name[digit-1] << "\n";
        } else{
            cout << name_to_num[input] << "\n";
        }
    }


    return 0;
}