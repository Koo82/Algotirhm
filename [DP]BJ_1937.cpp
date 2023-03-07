#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[500][500];
int dp[500][500];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int dfs(int r, int c) {
    if (dp[r][c] != -1) return dp[r][c];
    int &ans = dp[r][c];
    ans = 1;

    for (int i=0; i<4; i++) {
        int nr = r+dy[i];
        int nc = c+dx[i];

        if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n)) continue;
        if (arr[nr][nc] > arr[r][c]) {
            ans = max(ans, dfs(nr, nc) + 1);
        }
    }
    return ans;
}

int solve() {
    int sol = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            sol = max(sol, dfs(i,j));
        }
    }
    return sol;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n; // map size
    // map array input
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    fill(&dp[0][0], &dp[499][500], -1); // -1 initialization

    cout << solve() <<'\n';

    return 0;

}
