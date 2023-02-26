#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[15][15];
int t;
vector<int> k;
vector<int> n;
vector<int> sol;

void solve() {
    for (int i=1;i<15;i++) {
        dp[0][i] = i; // 0층 초기값 설정 
    }

    for (int i=1;i<15;i++) {
        for (int j=1;j<15;j++) {
            dp[i][j] = dp[i][j-1]+dp[i-1][j]; // 점화식 전개
        }
    }

    for (int i=0;i<t;i++) {
        sol.push_back(dp[k[i]][n[i]]); // inquery
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i=0;i<t;i++) {
        int t1, t2;
        cin >> t1 >> t2;
        k.push_back(t1);
        n.push_back(t2);
    }
    solve();
    for (int i=0;i<sol.size();i++){
        cout << sol[i] << '\n';
    }

    return 0;
}
