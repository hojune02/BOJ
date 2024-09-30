#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int a, b, c;
    vector<int> arr;
    cin >> a >> b >> c;
    while (!(a==0 && b==0 && c==0)){
        int res1 = c * c;
        int res2 = b * b;
        int res3 = a * a;
        if ((res1 == res2 + res3) || (res2 == res1 + res3) || (res3 == res1 + res2)){
            arr.push_back(1);
        } else{
            arr.push_back(0);
        }
        cin >> a >> b >> c;
    }

    for (int i = 0; i < arr.size(); i++){
        if (arr[i]){
            cout << "right" << "\n";
        } else{
            cout << "wrong" << "\n";
        }
    }
    return 0;
}