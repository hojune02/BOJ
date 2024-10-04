//백준 2751번: 수 정렬하기 2
#include <iostream>
using namespace std;

int main(){
    int N, elem;
    cin >> N;
    int arr[2000001];
    for (int i = 0; i < 2000001; i++){
        arr[i] = 0;
    }
    while (N--){
        cin >> elem;
        arr[elem + 1000000] = 1;
    }
    for (int i = 0; i <= 2000000; i++){
        if (arr[i] == 1) cout << (i - 1000000) << "\n";
        else continue;
    }

    return 0;
}