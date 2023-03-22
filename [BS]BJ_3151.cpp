#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[10010];

int lower_bound(int left, int num) {
    int l = left;
    int r = n;
    while (l<r) {
        int mid = (l+r)/2;
        if (arr[mid] < num) l = mid+1;
        else r = mid;
    }
    return l;
}

int upper_bound(int left, int num) {
    int l = left;
    int r = n;
    while (l<r) {
        int mid = (l+r)/2;
        if (arr[mid] <= num) l = mid+1;
        else r = mid;
    }
    return l;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(&arr[0], &arr[n]);
    // 첫 두수를 정하고 lower bounds와 upper bounds를 구해서 그 차이 값으로 최종 카운트
    // 배열 모두가 0이라면 10000C3가 되어, int 범위 초과 
    // long long을 사용해야 한다. 
    long long sol = 0;
    
    for (int i=0; i<=n-3;i++) {
        for (int j=i+1; j<=n-2;j++) {
            int _sum = arr[i]+arr[j];
            if (_sum >0) continue; // 가지치기 500ms 줄임
            sol += upper_bound(j+1, -_sum) - lower_bound(j+1, -_sum);
        }
    }
    cout << sol << '\n';
    return 0;
}
