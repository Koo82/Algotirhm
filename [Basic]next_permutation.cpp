#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_permutations(vector<int> &arr) {
    // 처음 순열은 오름차순, 마지막 순열은 내림차순
    int n = arr.size(); // arr size
    int i = n-1;
    //i>0 이면서 array의 역순으로 차례로 돌면서 뒤의 원소보다 앞의 원소가
    // 작을 때까지 진행 (switching 첫 원소)
    while(i>0 && arr[i-1] >= arr[i]) i -= 1;
    if (i<=0) return false; // 내림차순 정렬되면 false return 종료
    int j = n-1;
    // j 변수를 n-1부터 시작해서 a[i-1]보다 클 때까지 앞으로 진행 (switching 두번째 원소)
    while (arr[j] <= arr[i-1]) j-= 1;
    swap(arr[i-1], arr[j]);
    // i부터 끝까지 수의 순서를 뒤집는다. 초반에 i의 선정이 내림 차순 확인하며
    // 내려오기 때문에 다시 오름차순으로 만드는 과정 
    j = n-1;
    while (i <j) {
        swap(arr[i], arr[j]);
        i += 1; j -= 1;
    }
    return true;
}

bool prior_permutations(vector<int> &arr) {
    // 처음 순열은 내림차순, 마지막 순열은 오름차순
    int n = arr.size(); // arr size
    int i = n-1;
    //i>0 이면서 array의 역순으로 차례로 돌면서 뒤의 원소보다 앞의 원소가
    // 클 때까지 진행 (switching 첫 원소)
    while(i>0 && arr[i-1] <= arr[i]) i -= 1;
    if (i<=0) return false; // 내림차순 정렬되면 false return 종료
    int j = n-1;
    // j 변수를 n-1부터 시작해서 a[i-1]보다 작을 때까지 앞으로 진행 (switching 두번째 원소)
    while (arr[j] >= arr[i-1]) j-= 1;
    swap(arr[i-1], arr[j]);
    // i부터 끝까지 수의 순서를 뒤집는다. 초반에 i의 선정이 내림 차순 확인하며
    // 내려오기 때문에 다시 오름차순으로 만드는 과정 
    j = n-1;
    while (i <j) {
        swap(arr[i], arr[j]);
        i += 1; j -= 1;
    }
    return true;
}

void ns_next_permutations(vector<int> &arr) {
    // 처음 순열은 오름차순, 마지막 순열은 내림차순
    int n = arr.size(); // arr size
    int i = n-1;
    //i>0 이면서 array의 역순으로 차례로 돌면서 뒤의 원소보다 앞의 원소가
    // 작을 때까지 진행 (switching 첫 원소)
    while(i>0 && arr[i-1] >= arr[i]) i -= 1;
    if (i<=0) {
        reverse(arr.begin(), arr.end()); // 내림차순 정렬되면 전체 오름차순으로 변경
        return;
    } 
    int j = n-1;
    // j 변수를 n-1부터 시작해서 a[i-1]보다 클 때까지 앞으로 진행 (switching 두번째 원소)
    while (arr[j] <= arr[i-1]) j-= 1;
    swap(arr[i-1], arr[j]);
    // i부터 끝까지 수의 순서를 뒤집는다. 초반에 i의 선정이 내림 차순 확인하며
    // 내려오기 때문에 다시 오름차순으로 만드는 과정 
    reverse(arr.begin()+i+1, arr.end());
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr = {5, 4, 3, 1, 2};

    next_permutations(arr); //next_permutation

    for (int i=0;i<arr.size();i++) {
        cout << arr[i] << ' ';
    }
    cout <<'\n';

    prior_permutations(arr); // prior_permutation

    for (int i=0;i<arr.size();i++) {
        cout << arr[i] << ' ';
    }a
    cout <<'\n';

    ns_next_permutations(arr); // cyclic next permutation
    ns_next_permutations(arr);

    for (int i=0;i<arr.size();i++) {
        cout << arr[i] << ' ';
    }
    cout <<'\n';

    return 0;
}
