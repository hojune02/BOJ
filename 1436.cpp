//백준 1436번: 영화감독 숌
/*
How can we find nth 'doomsday number', which
contains 3 6s in its digits? The first few 'doomsday
numbers' are following:
666, 1666, 2666, 3666, 4666, 5666, 6066, ...
The problem suggests a brute-force approach.
*/
#include <iostream>
using namespace std;

bool checkFor3Sixes(int n){
    int count = 0;
    while (n > 0){
        int rem = n % 10;
        if (rem == 6){
            count++;
        } else {
            count = 0;
        }
        if (count == 3){
            return true;
        }
        n /= 10;
    }
    return false;
}

int nthDooms(int n){
    int count = 665;
    while (n > 0){
        count++;
        if (checkFor3Sixes(count)){
            n--;
        }
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    cout << nthDooms(N) << "\n";
    return 0;
}

/*
Let's read the problem carefully.. I got wrong outputs because
I firstly filtered out any number with three 6s, regardless of 
whether they are consecutive or not :(
*/