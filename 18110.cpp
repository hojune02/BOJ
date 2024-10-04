#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> arr;
    if (n == 0){
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i < n; i++){
        double elem;
        cin >> elem;
        arr.push_back(elem);
    }
    sort(arr.begin(), arr.end());

    double ignored = n * 0.15;
    double ceilIgnored = round(ignored);
    double sum = 0;
    for (int i = ceilIgnored; i < n - ceilIgnored; i++){
        sum += arr[i];
    }
    int sumR = round(sum/(n - 2*ceilIgnored));
    cout << sumR; 
    return 0;
}