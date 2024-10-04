//백준 17219번: 비밀번호 찾기
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    unordered_map<string, string> webpw;
    string str1, str2;
    for (int i = 0; i < N; i++){
        cin >> str1 >> str2;
        webpw[str1] = str2;
    }
    string target;
    for (int i = 0; i < M; i++){
        cin >> target;
        cout << webpw[target] << "\n";
    }
    return 0;
}