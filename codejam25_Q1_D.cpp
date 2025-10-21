#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <cassert>
#include <utility>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>
#include <random>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lbi(v, x) (lower_bound(all(v), x) - v.begin())
#define ubi(v, x) (upper_bound(all(v), x) - v.begin())
#define sz(a) ((int)a.size())
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using matrix = vector<vector<ll>>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vti = vector<ti>;
using vvti = vector<vti>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using vpl = vector<pl>;
using vvpl = vector<vpl>;
using vtl = vector<tl>;
using vvtl = vector<vtl>;
using vb = vector<bool>;
using vs = vector<string>;
using vvb = vector<vb>;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll gcd(ll a, ll b) { if (b==0) return a; else return gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a, b)*b; }
int ceil_pow(int n) {
    int x = 0;
    while((1U<<x) <(unsigned int)(n)) x++;
    return x;
}
vector<string> split_str(string s, const char delim = ' ') {
    vector<string> ret;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        ret.push_back(t);
    }
    return ret;
}
ll power(ll a, ll n, ll MOD) {
    if (n==0) return 1;
    else if (n%2 == 0) return power((a*a) % MOD, n/2, MOD);
    else return (a * power((a*a) % MOD, (n-1)/2, MOD)) % MOD;
}
ll inverse(ll a, ll p) {
    return power(a, p-2, p);
}
matrix mat_mul(const matrix &a, const matrix &b, ll MOD) {
    ll size = a.size(), size2 = a[0].size(), size3=b[0].size();
    matrix res(size, vl(size3, 0));
    for(ll i=0; i<size; ++i) {
        for(ll j=0; j<size3;++j) {
            for(ll k=0; k<size2;++k) { res[i][j] = (res[i][j] + (a[i][k] * b[k][j]+MOD) % MOD) % MOD; }
        }
    }
    return res;
}
matrix power(matrix a, ll n, ll MOD) {
    ll size = a.size();
    matrix res(size, vl(size));
    for(ll i =0; i<size;++i) res[i][i] = 1;
    while(n>0) {
        if (n%2) res = mat_mul(res, a, MOD);
        n /= 2;
        a = mat_mul(a, a, MOD);
    }
    return res;
}
vvi get_medidan(const vi &arr) {
    int as = arr.size();
    vvi ans(as, vi(as));
    for(int i=0; i<as; ++i) {
        priority_queue<int> maxheap;
        priority_queue<int, vi, greater<int>> minheap;
        for(int j=i; j<as; ++j) {
            if(minheap.size() == maxheap.size()) maxheap.push(arr[i]);
            else minheap.push(arr[i]);
            if(!minheap.empty() && minheap.top() < maxheap.top()) {
                int maxtop = maxheap.top(); maxheap.pop();
                int mintop = minheap.top(); minheap.pop();
                maxheap.push(mintop);
                minheap.push(maxtop);
            }
            if(!minheap.empty() && minheap.size() == maxheap.size()) ans[i][j] = (minheap.top()+maxheap.top())/2;
            else ans[i][j] = maxheap.top();
        }
    }
    return ans;
}
vb SieveOfEratosthenes(int n) {
    vb is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i <=n; i++) {
        if(is_prime[i]) { for(int j=i*i; j<=n; j+=i) is_prime[j] = false;}
    }
    return is_prime;
}
vi lis_list(vi arr) { // Longest Incresing sequence의 길이를 반환
    const int INF=0x3f3f3f3f;
    int n = sz(arr);
    vi lis_arr(n, 1); // 각 자리별 lis
    vi a_lis(n, INF);
    a_lis[0] = arr[0];
    int idx = 0;
    for(int i=1; i<n; ++i) {
        if(a_lis[idx]<arr[i]) {
            a_lis[++idx] = arr[i];
            lis_arr[i] = idx+1;
        }
        else {
            int n_idx = lbi(a_lis, arr[i]);
            assert(n_idx<n);
            a_lis[n_idx] = arr[i];
            lis_arr[i] = n_idx+1;
        }
    }
    return lis_arr; // lis 를 구하려면 lis_arr의 max값을 찾으면 된다.
}
template<typename T>
int popcount(T x) {return __builtin_popcountll(x);}
template<typename T>
void chmax(T &x, T y) {x = max(x, y);}
template<typename T>
void chmin(T &x, T y) {x = min(x, y);}
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}
vi calc_divisor(int n) { // n까지(포함)약수 갯수를 구하는 함수
    vi divi(n+1, 0);
    for(int i=1; i<n+1; ++i) {
        for(int j=1; j*i<n+1; ++j) {
            ++divi[j*i];
        }
    }
    return divi;
}
vl calc_divisor(ll x) { // x에 대한 약수 구하는 함수
    vl ans;
    for(ll i=2; i*i<=x; ++i) {
        if(x%i==0) {
            ans.push_back(i);
            if(i*i!=x) ans.push_back(x/i);
        }
    }
    return ans;
}
vl calc_prime_divisor(ll x) { // x에 대한 prime인 약수 구하는 함수
    vl ans;
    for(ll i=2; i*i<=x; ++i) {
        if(x%i==0) {
            ans.push_back(i);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) ans.push_back(x);
    return ans;
}
/////////////////////////////
struct bino {
    vector<ll> fac, inv, facinv;
    ll MOD = 998244353;
    bino(ll MOD):MOD(MOD)  {};

    void modcalc(int n=3000) { // factorial, inverse factorial 구하는 함수,
        fac.resize(n); inv.resize(n); facinv.resize(n);
        fac[0] = 1, fac[1] = 1;
        inv[1] = 1;
        facinv[0] = 1, facinv[1] = 1;
        for(int i=2; i<n; ++i) {
            fac[i] = fac[i-1] * i %MOD;
            inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
            facinv[i] = facinv[i-1] * inv[i] % MOD;
        }
        // facinv[n-1] = power(fac[n-1], MOD-2, MOD);
        // for (int i = n-1; i >= 1; --i) facinv[i - 1] = ((ll)facinv[i] * i)%MOD;
    }
    ll comb(int n, int k) { // combination 수 구하는 함수
        if(n<0 || k<0 || n<k) return 0;
        return (fac[n] * facinv[n-k] % MOD) * facinv[k] % MOD;
    }
    ll perm(int n, int k) {return comb(n, k) * fac[k] % MOD;}
    ll Homo(int n, int k) {return comb(n+k-1, k) % MOD;}
};
////////////////////////////////////////
// SCC algorithm
// 1) Each vertex is in exactly one list of the vertices.
// 2) Each list of the vertices corresponds to the vertex set of a strongly connected component. The order of the vertices in the list is undefined.
// 3)The list of list of the vertices are sorted in topological order, i.e., for two vertices u, v in different strongly connected components, if there is a directed path from u to v, the list contains u appears earlier than the list contains v.
namespace atcoder {
namespace internal {
template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};
}  // namespace internal
}  // namespace atcoder

namespace atcoder {
namespace internal {
struct scc_graph {
public:
    scc_graph(int n) : _n(n) {}
    int num_vertices() { return _n; }
    void add_edge(int from, int to) { edges.push_back({from, {to}}); }
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }
    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }
private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
}  // namespace internal
}  // namespace atcoder

namespace atcoder {
struct scc_graph {
public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}
    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }
    std::vector<std::vector<int>> scc() { return internal.scc(); }
private:
    internal::scc_graph internal;
};
}  // namespace atcoder
using namespace atcoder;
/////////////////////////////////////////////////////////
struct dsu {
    public:
        dsu(): _n(0) {}
        dsu(int n): _n(n), parent_or_size(n, -1) {}

        int merge(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            int x = leader(a), y = leader(b);
            if (x==y) return x;
            if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            return x;
        }

        bool same(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            return leader(a) == leader(b);
        }

        int leader(int a) {
            assert(0 <= a && a < _n);
            if(parent_or_size[a] < 0) return a;
            return parent_or_size[a] = leader(parent_or_size[a]);
        }

        int size(int a) {
            assert(0 <= a && a < _n);
            return -parent_or_size[leader(a)];
        }

        vvi groups() {
            vi leader_buf(_n), group_size(_n);
            for (int i=0; i< _n; ++i) {
                leader_buf[i] = leader(i);
                group_size[leader_buf[i]]++;
            }
            vvi result(_n);
            for(int i=0; i<_n; ++i) {
                result[i].reserve(group_size[i]);
            }
            for(int i=0; i<_n; ++i) {
                result[leader_buf[i]].push_back(i);
            }
            result.erase(remove_if(result.begin(), result.end(), [&](const vi& v) {return v.empty();}), result.end());
            return result; 
        }

    private:
        int _n;
        vi parent_or_size;
};
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }
    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
namespace atcoder {
namespace internal {

    int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {
    return __builtin_ctz(n);
}
}  // namespace internal
}  // namespace atcoder
namespace atcoder {
// lazy seg 인자 정의 
// using S = int; // lazy seg 기본 class
// using F = int; // lasy seg 변형 class
// S op(S a, S b) {return a+b;} // lazy seg 기본 operation
// S e() {return 0;} // 기본 operation 항등원
// S mapping(F l, S r) {return r+l;} // 변형 operation 구현
// F composition(F l, F r) {return l+r;} // 변형 operation compose
// F id() {return 0;} // 변형 operation 항등원
template <class S,
            S (*op)(S, S),
            S (*e)(),
            class F,
            S (*mapping)(F, S),
            F (*composition)(F, F),
            F (*id)()>
struct lazy_segtree {
    public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

    private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
}  // namespace atcoder
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
    Edge(int u, int v, int weight):u(u), v(v), weight(weight) {}
};
struct Kruskal {
public:
    Kruskal(int n):num_node(n) {}
    void add_edge(int u, int v, int weight) {
        edges.push_back(Edge(u, v, weight));
    }
    ll mst() {
        asort(edges);
        dsu dj(num_node);
        // vector<Edge> results;
        int cnt = 0;
        for(Edge e: edges) {
            if(dj.leader(e.u) != dj.leader(e.v)) {
                mst_res+= e.weight;
                // results.push_back(e);
                dj.merge(e.u, e.v);
                ++cnt; // 결합되는 edge의 갯수를 반환
            }
        }
        if(cnt<num_node-1) return LINF;
        return mst_res;
    }
private:
    vector<Edge> edges;
    int num_node;
    ll mst_res = 0;
    const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
};
struct BipartiteMatching {
    int n;
    int source, sink;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    BipartiteMatching(int n) : n(n) {
        graph.resize(n);
        check.resize(n);
        pred.resize(n,-1);
    };
    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }
    bool dfs(int x) {
        if (x == -1) return true;
        for (int next : graph[x]) {
            if (check[next]) continue;
            check[next] = true;
            if (dfs(pred[next])) {
                pred[next] = x;
                return true;
            }
        }
        return false;
    }
    int flow() {
        int ans = 0;
        for (int i=0; i<n; i++) {
            fill(check.begin(),check.end(),false);
            if (dfs(i)) {
                ans += 1;
            }
        }
        return ans;
    }
};
ll range_sum(vl& psum, int l, int r) {
    if(l>r) return 0ll;
    return psum[r+1] - psum[l];
}
struct manacher { // palindrome을 찾아내는 알고리즘 O(n)
    string s;

    manacher(string s): s(s) {}
    vi calc_odd(string t) {
        int n = sz(t);
        t = "$" + t + "^";
        vi p(n+2);
        int l = 0, r = 1;
        for(int i=1; i<=n; ++i) {
            p[i] = max(0, min(r-i, p[l+(r-i)]));
            while(t[i-p[i]] == t[i+p[i]]) {
                p[i]++;
            }
            if(i+p[i]>r) {l=i-p[i], r = i+p[i];}
        }
        return vi(begin(p)+1, end(p)-1);
    }
    vi calc() {
        string t;
        for(auto c: s) {
            t += string("#") + c;
        }
        auto res = calc_odd(t + "#");
        return vi(begin(res)+1, end(res)-1); // i%2==1 even_palindrome/2+1, i%2==0, odd_palindrome길이/2 
    }
};
struct Hash {
    // 1<= ㅣ<=r <=n 의 범위 psum과 같다고 보면 된다. 
    // ll p = 31, m = 1e9+7;
    const long long MOD = ((long long) 1 << 61) - 1;
    const long long BASE = 436589236487;
    long long mul(long long a, long long b){ return (__int128_t) a * b % MOD;}
    int n;
    vl p_pow, h;
    Hash(const string& s) {
        n = sz(s);
        p_pow = vl(n+1, 1);
        h = vl(n+1, 0);
        loop(i, 1, n+1) p_pow[i] = (p_pow[i-1]*BASE) %MOD;
        loop(i, 1, n+1) h[i] = (h[i-1]*BASE + (s[i-1] - 'a' + 1)) % MOD;
    }
    ll get_hash(int l, int r) { // index 1부터 시작 
        return (h[r] - (h[l-1] * p_pow[r-l+1])% MOD + MOD)% MOD;
    }
};
////////////////////////////////////
template<typename T> T op_max(T x, T y) {return max(x,y);}
template<typename T> T op_min(T x, T y) {return min(x,y);}

template<typename T,  T (*op)(T, T)>
struct sparse_table {
    int n,m;
    vector<vector<T>> table;

    inline T merge(T x, T y) {
    return op(x, y);
    }

    sparse_table(vector<T> &a) {
        n = a.size();
        m = __lg(n) + 1;
        table.assign(m, vector<T>(n));
        for (int i = 0; i < n; i++) table[0][i] = a[i];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j + (1<<i) <= n; j++) {
                table[i][j] = merge(table[i-1][j], table[i-1][j + (1<<(i-1))]);
            }
        }
    }

    T query(int l, int r) {
        // l, r : inclusive
        assert(l<=r && 0<=l && r< n);
        int u = __lg(r-l+1);
        return merge(table[u][l], table[u][r-(1<<u)+1]);
    }

    T query(int l, int r, T e) {
        // e for identity
        l = max(l,0);
        r = min(r,n-1);
        int u = __lg(r-l+1);
        if (l<=r) return merge(table[u][l], table[u][r-(1<<u)+1]);
        else return e;
    }
};

template<typename T> using max_spt = sparse_table<T,op_max>;
template<typename T> using min_spt = sparse_table<T,op_min>;

////////////////////////////////////////////////
template<typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
//min_pq<tuple<int,int,int>> pq; 
template<typename Container> void show(Container&& c)
{
    for (const auto& n : c)
        std::cout << n << ", ";
    std::cout << std::endl;
}

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
// iota(all(x), initval) : initval로 시작하는 연속된 정수로 x 채워줌
// line의 경우 vector의 형태 ax + t(bx-ax)의 형태로 formulation하는 것이 수식에 유리
// string 확장에는 s2 = string(sz_diff, '0')+s2; 와 같이 접근해야지 절대 while(sz_diff--) s2 = "0"+s2; 접근하면 안된다.
// ordered_set, st.order_of_key(num) : ordered_set에서 num보다 작은(미만) 원소의 갯수 반환, 
//              st.find_by_order(k) : ordered_set에서 (k+1) 번째 원소가 있는 iterator 반환 (k==0 이면 1번째)
// int op(int a, int b) { return min(a, b);}
// int e() { return (int)(1e9);}
// segtree<int, op, e> seg(10);
// mt19937 rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count()); // random 수
// int st = 0, en = 2147483647;                  // [st, en]
// uniform_int_distribution<int> rnd(st, en);    // 수 범위 설정 
// int i = rnd(rd);                              // 수 추출

int t, n, m, k;
vpl up, down, arr;
vector<vvl> dp;

ll calc(int u, int d, int dir, int pos) {
    if(u>=m && d>=k) return 0;

    if(dp[u][d][dir] != LINF) return dp[u][d][dir];
    ll& ans = dp[u][d][dir];

    // if(u==0 && d==0) {
    //     ans = min(ans, abs(pos-up[0].first)*up[0].second+calc(1, 0, 1, pos));
    //     ans = min(ans, abs(pos-down[0].first)*down[0].second+calc(0, 1, 2, pos));
    // }
    // else {
    if(d<k) {
        if(dir==0) {
            ll temp = pos*pos+abs(down[1].first-pos)*down[1].second;
            ans = min(ans, pos*pos+abs(down[1].first-pos)*down[1].second+calc(u, 1, 2, pos));
        }
        else if(dir==1) {
            ll temp = abs(down[d+1].first-up[u].first)*down[d+1].second;
            ans = min(ans, abs(down[d+1].first-up[u].first)*down[d+1].second+calc(u, d+1, 2, pos));
        } 
        else if(dir==2) {
            ll temp = abs(down[d+1].first-down[d].first)*down[d+1].second;
            ans = min(ans, abs(down[d+1].first-down[d].first)*down[d+1].second+calc(u, d+1, 2, pos));
        }            
    }
    if(u<m) {
        if(dir==0) {
            ll temp = pos*pos+abs(up[1].first-pos)*up[1].second;
            ans = min(ans, pos*pos+abs(up[1].first-pos)*up[1].second+calc(1, d, 1, pos));
        }
        else if(dir==1) {
            ll temp = abs(up[u+1].first-up[u].first)*up[u+1].second;
            ans = min(ans, abs(up[u+1].first-up[u].first)*up[u+1].second+calc(u+1, d, 1, pos));
        }
        else if(dir==2) {
            ll temp = abs(up[u+1].first-down[d].first)*up[u+1].second;
            ans = min(ans, abs(up[u+1].first-down[d].first)*up[u+1].second+calc(u+1, d, 1, pos));
        }
    }
    
    // }
    return ans;
}

ll solve(int pos) {
    // int q1 = (lo+span), q2 = (lo+span*2);
    up = vpl(); down = vpl();
    up.push_back({0,0}), down.push_back({0,0});
    rep(i, n) {
        if(arr[i].first>pos) up.push_back(arr[i]);
        else down.push_back(arr[i]);
    }
    m = sz(up), k = sz(down);
    --m; --k;
    sort(up.begin()+1, up.end()), sort(down.begin()+1, down.end(), greater());
    // reverse(down.begin(), down.end());
    dp = vector<vvl>(m+1, vvl(k+1, vl(3, LINF)));

    return calc(0, 0, 0, pos);
}


int main() {
    fastio;
    cin >> t;
    while(t--) {
        cin >> n;
        arr = vpl(n);
        int mn = 0, mx = 0;
        rep(i, n) {
            ll p, w; cin >> p >> w;
            arr[i] = {p, w};
            mn = min(mn, (int)p), mx = max(mx, (int)p);
        }
        int lo = mn, hi = mx;
        while(hi-lo >= 3) {
            int span = (hi-lo)/3;
            int q1 = (lo+span), q2 = (lo+span*2);
            // up = vpl(); down = vpl();
            // rep(i, n) {
            //     if(arr[i].first>q1) up.push_back(arr[i]);
            //     else down.push_back(arr[i]);
            // }
            // m = sz(up), k = sz(down);
            // asort(up), dsort(down);
            // vector<vvl> dp(m+1, vvl(k+1, vl(3, LINF)));
            // ll l = solve(q1);
            ll l = solve(q1);
            ll r = solve(q2);
            
            if(solve(q1) <= solve(q2)) hi = q2;
            else lo = q1;
        }
        ll ans = LINF;
        loop(i, lo, hi+1) {
            ans = min(ans, solve(i));
        }
        cout << ans << "\n";
    }




    //cout << fixed << setprecision(20);
    return 0;
}
