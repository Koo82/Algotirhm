#include <iostream>
#include <algorithm>
#include <vector>

int inf = 0x7fffffff;
int n, m;
using namespace std;

int check(int* arr) {
    int sol = inf;
    int l = 0; // left pointer
    int r = 0; // right pointer
    //어느 한 pointer가 리스트에 끝에 도달할 때까지 진행 
    while ((l < n) && (r < n)) {
        if (arr[r] - arr[l] < m) r += 1; // 두 값의 차가 m보다 작으면 right pointer 증가
        else { // 그렇지 않으면 솔루션 저장하고 left pointer 증가
            sol = min(sol, arr[r]-arr[l]);
            l += 1;
        }
    }
    return sol;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cout << check(arr) << '\n';

    return 0;
}
