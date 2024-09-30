//백준 2166번: 다각형의 면적
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iomanip>
using namespace std;

const int maxN = 10000;
pair<long double, long double> coords[maxN];

long double calculateArea(pair<long double, long double> coords[], int N){
    long double sum = 0;
    for (int i = 0; i < N - 1; i++){
        sum += (coords[i].first * coords[i+1].second - coords[i].second * coords[i+1].first);
        //cout << (coords[i].first * coords[i+1].second - coords[i].second * coords[i+1].first) << "\n";
    }
    sum += coords[N-1].first * coords[0].second - coords[N-1].second * coords[0].first;
    sum /= 2;
    sum = abs(sum);
    long double rounded = round(sum * 10) / 10;
    return rounded;

}

int main(){
    int N;
    long double a, b;
    cin >> N;
    int i = 0;
    int originalN = N;
    while (N--){
        cin >> a >> b;
        coords[i] = make_pair(a, b);
        i++;
    }
    long double area = calculateArea(coords, originalN);
    cout << fixed << setprecision(1) << area << "\n";
    return 0;
}