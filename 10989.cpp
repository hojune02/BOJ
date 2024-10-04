//백준 10989번: 수 정렬하기 3
//제한시간 8초에 메모리 제한 8MB...그냥 브루트포스 써도 되려나?
//Let's use insertion sort!
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N, num;
    cin >> N;
    int nums[10000+1];
    for (int i = 0; i < 10001; i++){
        nums[i] = 0;
    }
    for (int i = 0; i < N; i++){
        cin >> num;
        nums[num] += 1;
    }
    for (int i = 0; i < 10000+1; i++){
        if (nums[i] == 0){
            continue;
        } else{
            for (int j = 0; j < nums[i]; j++){
                cout << i << "\n";
            }
        }
    }

    return 0;
}