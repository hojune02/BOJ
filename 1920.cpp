//백준 1920번: 수 찾기
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

bool binaryFind(int arr[], int target, int start, int end){
    if (start >= end){
        if (target == arr[end]) return true;
        else return false;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == target){
        return true;
    } else if (arr[mid] < target){
        return binaryFind(arr, target, mid + 1, end);
    } else {
        return binaryFind(arr, target, start, mid);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N;
    int results[N];
    for (int i = 0; i < N; i++){
        int elem;
        cin >> elem;
        results[i] = elem;
    }
    sort(results, results + N);
    cin >> M;
    for (int i = 0; i < M; i++){
        int elem;
        cin >> elem;
        if (binaryFind(results, elem, 0, N-1)){
            cout << "1\n";
        } else{
            cout << "0\n";
        }
    }

}