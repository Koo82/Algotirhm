#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;
vector<int> v[100001];

// 기본적인 bfs, vector와 deque를 활용
int bfs(int start, int end) {
    deque<pair<int, int>> q;
    bool visit[100001];
    memset(visit, false, sizeof(visit));

    q.push_back(make_pair(start, 1));
    visit[start] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop_front();
        int pos = cur.first;
        int length = cur.second;

        if (pos == end) {
            return length;
        }
        for (int i=0; i<v[pos].size(); i++) {
            int npos = v[pos][i];
            if (visit[npos]) continue;
            visit[npos] = true;
            q.push_back(make_pair(npos, length+1));
        }
    }
    return 0; // 쓰레기 값이 나오는 것을 막아주려면 q를 그냥 통과했을 때 기본 값을 주어야 한다.
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s, c, h;

    cin >> n >> s >> c >> h;
    // 무방향 그래프 생성
    for (int i=0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 현재의 그래프 구조가 n개의 노드에 n-1개의 간선으로 이루어져 있기 때문에
    // 순환이 존재하지 않고 한 포인트에서 다른 포인트로 가는 경로가 유일하다는 것을 유념해 둬야함
    // 중간 심부름을 거쳐 최종 목적지 까지 도달하는 거리 (중간 심부름 2번 포함하여 1 빼줌)
    int start_m_f = bfs(s, c) + bfs(c, h) - 1;
    // 중간 심부름을 거치지 않고 최종 목적지까지 도달하는 거리
    int start_to_f = bfs(s, h);

    // 중복된 원소 갯수 계산
    // 최소경로로 심부름까지 진행했고, 최소 경로로 목적지까지 진행하기 때문에,
    // 유일한 경로에서 심부름을 거쳤다 가는 거리와 목적지 바로 가는 것의 차이는 중복된 노드 *2 갯수 만큼 차이가 난다
    // 노드를 계산할 때 중복없는 조합의 갯수를 구하고, 중복이 있는 부분에 대해서는 뒤집어서 노드 형성이 가능하므로 이 부분 더해준다.
    long long dup_point = (start_m_f - start_to_f)/2;
    long long non_dup_point = start_m_f - dup_point;
    long long ans = (non_dup_point*(non_dup_point-1) + dup_point *(dup_point+1))/2; // long long으로 받지 않으면 overflow 오답

    cout << ans << '\n';

    return 0;
}
