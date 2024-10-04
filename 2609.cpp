//백준 2609번: 최대공약수와 최소공배수
//Using Euclidean Algorithm
#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int bigger = (a>b)? a : b;
    int smaller = (a>b)? b : a;
    int r = bigger % smaller;
    while (r > 0){
        int originalr = r;
        r = smaller % r;
        smaller = originalr;
    }
    cout << smaller << "\n";

    int minProduct = a * b / smaller;
    cout << minProduct;

    return 0;
}