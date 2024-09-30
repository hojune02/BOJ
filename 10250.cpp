//백준 10250번: ACM 호텔
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    int originalT = T;
    vector<int> hArr;
    vector<int> wArr;
    while (T--){
        int H, W, N;
        cin >> H >> W >> N;
        int h = N % H;
        int w = N / H + 1;
        if (h == 0) {/*
        When h is a multiple of N, it evaluates into 0.
        Also, w increases by 1 when it is not supposed to.
        Hence, set h = H and w -= 1 to correct this.
        */
            h = H;
            w -= 1;
        }
        if (w < 10) h *= 10;
        hArr.push_back(h);
        wArr.push_back(w);
    }
    for (int i = 0; i < originalT; i++){
        cout << hArr[i] << wArr[i] << "\n";
    }
    return 0;
}