//백준 10816번: 숫자 카드 2
#include <iostream>
using namespace std;

int solve(int arr[], int target, int start, int end){
    if (start > end){
        return 0;
    } 
    if (start == end){
        if (arr[end] == target){
            return 1;
        } else{
            return 0;
        }
    }
    int mid  = (start + end) / 2;
    if (arr[mid] == target){
        return 1 + solve(arr, target, start, mid) + solve(arr, target, mid + 1, end);
    } else if (arr[mid] > target){
        return solve(arr, target, start, mid);
    } else {
        return solve(arr, target, mid + 1, end);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++){
        int elem;
        cin >> elem;
        arr[i] = elem;
    }   
    sort(arr, arr+N);
    cin >> M;
    int results[M];
    for (int i = 0; i < M; i++){
        int target;
        cin >> target;
        int count = solve(arr, target, 0, N-1);
        results[i] = count;
    }


    return 0;
}

/*
//백준 10816번: 숫자 카드 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++){
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }   
    sort(arr.begin(), arr.end());

    cin >> M;
    int results[M];
    for (int i = 0; i < M; i++){
        int target;
        cin >> target;
        int count = upper_bound(arr.begin(), arr.end(), target) - lower_bound(arr.begin(), arr.end(), target);
        results[i] = count;
    }
    for (int i = 0; i < M; i++){
        cout << results[i] << " ";
    }
    cout << "\n";

    return 0;
}
*/