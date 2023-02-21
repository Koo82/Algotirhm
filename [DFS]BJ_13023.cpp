#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define _max 2000
// int _max = 2000;
vector<int> graph[_max];
bool check[_max];


bool dfs(int num, int cnt) {
    if (cnt >=4) return true;
    // check[num] = True;
    
    // size로 접근하면 연결이 없을 시에 0이기 때문에 자동 기각됨
    for (int i =0;i<graph[num].size();i++){
        int nex = graph[num][i];
        if (check[nex]) continue;
        check[nex] = true;
        if (dfs(nex, cnt+1)) return true;
        check[nex] = false;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input 값 처리
    int n, m;
    cin >> n >> m;
    int a, b;
    int sol = 0;
    for (int i=0; i<m;i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); 
    }

    for (int i=0; i<2000; i++) {
        fill(&check[0], &check[_max], false);
        check[i] = true;
        if (dfs(i, 0)) {
            sol = 1;
            break;
        }
    }

    cout << sol << '\n';

    return 0;
}
