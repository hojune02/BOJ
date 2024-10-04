//백준 28702번: FizzBuzz
/*
I think using stoi to convert any given number is going
to be quite useful. Also, What if the given three inputs 
are all "Fizz", "Buzz", and/or "FizzBuzz"? Hmm...


*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int add = 3;
    int result;
    string strs[3];
    for (int i = 0; i < 3; i++){
        cin >> str;
        strs[i] = str;
    }
    for (int i = 0; i < 3; i++){
        if (strs[i][0] == 'F' || strs[i][0] == 'B'){
            add--;
            continue;
        } else{
            int num = stoi(strs[i]);
            result = num + add;
            break;
        }
    }
    if (result % 3 == 0 && result % 5 == 0){
        cout << "FizzBuzz";
    } else if (result % 5 == 0){
        cout << "Buzz";
    } else if (result % 3 == 0){ 
        cout << "Fizz";
    } else{
        cout << result;
    }



    return 0;
}