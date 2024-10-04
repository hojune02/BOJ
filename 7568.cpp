//백준 7568번: 덩치
#include <iostream>
#include <vector>
using namespace std;

int cmpDC(pair<int, int> a, pair<int, int> b){
    if (a.first > b.first && a.second > b.second){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int N;
    cin >> N;
    pair<int, int> pairs[N];
    int results[N];
    for (int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        pairs[i] = make_pair(x, y);
    }
    for (int i = 0; i < N; i++){
        results[i] = 1;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i != j){
                if (cmpDC(pairs[j], pairs[i])){
                    results[i] += 1;
                }
            }
        }
    }
    for (int i = 0; i < N; i++){
        cout << results[i] << " ";
    }
    cout << "\n";

    return 0;
}