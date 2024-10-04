//백준 2775번: 부녀회장이 될테야
//Use dynamic programming, since the number of people
// on a-1th floor affects the number of people on ath floor
#include <iostream>
#include <vector>
using namespace std;
int apartment[15][15];

int main(){
    vector<int> aparts;
    for (int i = 1; i <= 14; i++){
        apartment[0][i] = i;
    }
    for (int i = 1; i <= 14; i++){
        for (int j = 1; j <= 14; j++){
            if (j == 1){
                apartment[i][j] = 1;
            } else{
                apartment[i][j] = apartment[i][j-1] + apartment[i-1][j];
            }
        }
    }
    int T, i, j;
    cin >> T;
    while (T--){
        cin >> i >> j;
        aparts.push_back(apartment[i][j]);
    }
    for (int i = 0; i < aparts.size(); i++){
        cout << aparts[i] << "\n";
    }
    return 0;
}