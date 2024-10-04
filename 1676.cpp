//백준 1676번: 팩토리얼 0의 개수
#include <iostream>
using namespace std;


int check0sInFac(int n){
    int count2 = 0;
    int count5 = 0;
    for (int i = 1; i <= n; i++){
        if (i % 2 == 0){
            int originali = i;
            while (i % 2 == 0){
                count2++;
                i /= 2;
            }
            i = originali;
        }
        if (i % 5 == 0){
            int originali = i;
            while (i % 5 == 0){
                count5++;
                i /= 5;
            }
            i = originali;
        }
    }
    if (count2 <= count5){
        return count2;
    } else{
        return count5;
    }
}

int main(){
    int N;
    cin >> N;
    cout << check0sInFac(N) << "\n";
    return 0;
}
/*
My original approach was to calculate the actual value
of factorial(N) and count the number of zeros. But this exceeds
the limit of long long int very easily, causing overflow.

I should be counting the occurrences of 2 and 5 in the prime 
factorisation of the natural numbers less than or equal to n
*/