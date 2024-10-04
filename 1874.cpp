//백준 1874번: 스택 수열
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int N;
    cin >> N;
    deque<int> seq;
    for (int i = 0; i < N; i++){
        int elem;
        cin >> elem;
        seq.push_back(elem);
    }

    deque<int> ascendingNums;
    for (int i = 1; i <= N; i++){
        ascendingNums.push_back(i);
    }
    deque<int> stk;
    vector<char> result;
    int count = 1;
    while (true){
        if ((stk.empty() && !seq.empty() || seq.front() > stk.back())){
            while(!ascendingNums.empty() && (ascendingNums.front() <= seq.front())){
                stk.push_back(ascendingNums.front());
                ascendingNums.pop_front();
                result.push_back('+');
            }
        } else if (!stk.empty() && !seq.empty()){ // both not empty
            if (stk.back() == seq.front()){
                stk.pop_back();
                seq.pop_front();
                result.push_back('-');
                if (stk.empty() && seq.empty()){
                    break;
                }
            } else{
                cout << "NO" << "\n";
                return 0;
            }
        } else if (!stk.empty() && seq.empty()){
            cout << "NO" << "\n";
            return 0;
        } else{ // both empty
            break;
        }
    }
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << "\n";
    }
    return 0;
}