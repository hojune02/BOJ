//백준 8958번: OX퀴즈
#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    int T;
    cin >> T;
    int result[T];
    for (int x = 0; x < T; x++){
        cin >> input;
        int correct[input.length()];
        int sum = 0;
        for (int i = 0; i < input.length(); i++){
            if (input[i] == 'O'){
                correct[i] = 1;
            } else{
                correct[i] = 0;
            }
        }
        for (int i = 0; i < input.length(); i++){
            if (i == 0) continue;
            else{
                if (correct[i-1] > 0 && correct[i] > 0){
                    correct[i] += correct[i-1];
                }
            }
        }
        for (int i = 0; i < input.length(); i++){
            sum += correct[i];
        }
        result[x] = sum;
    }

    for (int i = 0; i < T; i++){
        cout << result[i] << "\n";
    }
    return 0;
}