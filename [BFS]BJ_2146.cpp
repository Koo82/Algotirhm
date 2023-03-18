#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <deque>

using namespace std;
int n;
int arr[100][100];
bool check[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int bfs() {
    int cat = 1;
    int sol = 10000;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) {
            if (arr[i][j] != 1) continue; // 1이 아니라면 탐색 시작할 필요 없음
            cat += 1; // group categorizing index, 2번 부터 형성
            deque<pair<int, int>> q1; // BFS 그룹 형성을 위한 배열
            deque<tuple<int,int, int>> q2; // BFS 현재 그룹 queue
            q1.push_back(make_pair(i,j));
            q2.push_back(make_tuple(0,i,j));
            arr[i][j] = cat; // 그룹 원소 배열 형성
            while (q1.size()) {
                int y, x, ny, nx;
                y = q1.front().first;
                x = q1.front().second;
                q1.pop_front();
                for (int k=0;k<4;k++) {
                    ny = y+dy[k];
                    nx = x+dx[k];
                    if ((ny<0) || (ny>=n) || (nx<0) || (nx>=n)) continue;
                    if (arr[ny][nx] != 1) continue;
                    q1.push_back(make_pair(ny,nx));
                    q2.push_back(make_tuple(0,ny,nx));
                    arr[ny][nx] = cat;
                }
            }
            fill(&check[0][0], &check[99][100], false);
            bool flag = false;
            while (q2.size()) {
                int cost, y, x, ny, nx;
                cost = get<0>(q2.front());
                y = get<1>(q2.front());
                x = get<2>(q2.front());
                q2.pop_front();
                if (flag || (cost >= sol)) break;
                for (int k=0;k<4;k++) {
                    ny = y + dy[k];
                    nx = x + dx[k];
                    if ((ny<0) || (ny>=n) || (nx<0) || (nx>=n)) continue;
                    if (check[ny][nx]) continue;
                    if (arr[ny][nx] != 0) {
                        if (arr[ny][nx] != cat) {
                            sol = min(sol, cost);
                            flag = true;
                            break;
                        }
                        else continue;
                    }
                    q2.push_back(make_tuple(cost+1, ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력값 처리
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    cout << bfs() << '\n';
    return 0;
}



