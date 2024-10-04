//백준 11866번: 요세푸스 문제 0
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void josephus(int n, int k){
    deque<int> temp;
    for (int i = 1; i <= n; i++){
        temp.push_back(i);
    }
    vector<int> result;
    while(!temp.empty()){
        for (int i = 0; i < k-1; i++){
            int elem = temp.front();
            temp.push_back(elem);
            temp.pop_front();
        }
        result.push_back(temp.front());
        temp.pop_front();
    }
    cout << "<";
    for (int i = 0; i < result.size() - 1; i++){
        cout << result[i] << ", ";
    }
    cout << result[result.size()-1] << ">";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    josephus(N, K);
    return 0;
}