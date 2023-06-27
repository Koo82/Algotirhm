#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using matrix = vector<vector<ll>>;
#define MOD 998'244'353

template<class T>
void printMatrix(vector<vector<T>> const &matrix) {
    for (vector<T> row: matrix) {
        for (T val: row) {
            cout << val << ' ';
        }
        cout << '\n';
    }
}
template<class T>
void printVector(vector<T> const &vect) {
    for (T val: vect) {
        cout << val << ' ';
    }
    cout << '\n';
}

// nCr = n-1Cr-1 + n-1Cr 원리를 그대로 이용
ll combination(int n, int r) {
    if (n == r || r == 0) return 1;
    else return combination(n-1, r-1) + combination(n-1, r);
}

int k;
vector<int> dancing_score(300000, 0);
vector<int> facto(300000, 1);
vector<int> prize(20, 0);
vector<int> multiple_2(20, 1);
int cnt;

ll power(ll a, ll n) {
    if (n==0) return 1;
    else if (n%2 == 0) return power((a*a) % MOD, n/2);
    else return (a * power((a*a) % MOD, (n-1)/2)) % MOD;
}

// count C multiple_2[i]-1 * (multiple_2[i]-1)! * (multiple_2[k] - multiple_2[i])! * prize[i] / (multiple_2[k]-1)
ll solve() {
    ll ans = 0;
    for (int i=1; i<=k; ++i) {
        ll t_ans = 1;
        if (cnt >= multiple_2[i] -1) {
            t_ans = t_ans * prize[i] % MOD;
            t_ans = t_ans * facto[cnt] % MOD;
            t_ans = t_ans * facto[multiple_2[i]-1] % MOD;
            t_ans = t_ans * facto[multiple_2[k] - multiple_2[i]] % MOD;
            t_ans = t_ans * power(facto[multiple_2[i]-1], MOD-2) % MOD;
            t_ans = t_ans * power(facto[cnt - multiple_2[i]+1], MOD-2) % MOD;
            t_ans = t_ans * power(facto[multiple_2[k]-1], MOD-2) % MOD;
            ans = (ans + t_ans) % MOD;
        }
        else break;
    }
    return ans;
}

int main() {
    fastio;
    cin >> k;
    int limit = 1;
    int gomgom;
    for (int i=1; i<=k; ++i){
        multiple_2[i] = multiple_2[i-1] * 2;
    }
    cin >> dancing_score[0];
    for (int i=1; i<multiple_2[k]; ++i) {
        cin >> dancing_score[i];
        if (dancing_score[i] < dancing_score[0]) {
            cnt += 1;
        }
    }
    for (int i=1; i<=k;++i) {
        cin >> prize[i];
    }
    for (int i=1; i<300'000; ++i) {
        facto[i] = facto[i-1] * i % MOD;
    }

    cout << solve() << '\n';
    return 0;
}
