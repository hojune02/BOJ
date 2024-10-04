//백준 31403번: A + B - C
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    cout << stoi(a) + stoi(b) - stoi(c) << "\n";
    cout << stoi(a+b) - stoi(c);
    return 0;
}