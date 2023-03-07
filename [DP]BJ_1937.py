# dfs approach and using dynamic programming to keep max path from specific point.
# if we calculate max path from certain points, we don't need to recalculate it any more

# Top-down
import sys
sys.setrecursionlimit(2000*2000)
rdln = sys.stdin.readline

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
n = int(rdln())
a = [list(map(int, rdln().split())) for _ in range(n)]
d = [[0]*n for _ in range(n)]

def go(i, j):
    if d[i][j] != 0: # 이미 방문한 값은 최적값이므로 그대로 반영
        return d[i][j]
    d[i][j] = 1 # 시작한 위치 자체도 1개로 포함되므로, 최소값은 1이다.
    for k in range(4):
        y, x = i +dy[k], j+dx[k]
        if 0 <= x < n and 0 <= y < n:
            if a[i][j] < a[y][x]: # 대나무 개수가 많아야 진행
                d[i][j] = max(d[i][j], go(y, x) + 1)
    return d[i][j]
ans = 0
for i in range(n):
    for j in range(n):
        ans = max(ans, go(i,j))
print(ans)

# Bottom-up
import sys
rdln = sys.stdin.readline

dx, dy = [0, -1, 0, 1], [-1, 0, 1, 0]
n = int(rdln())
a = [list(map(int, rdln().split())) for _ in range(n)]
d = [[0]*n for _ in range(n)]
b = []

for i in range(n):
    for j in range(n):
        b.append((i,j,a[i][j]))

b.sort(key=lambda val: -val[2])

# 팬더는 대나무가 작은 곳에서 많은 곳으로 이동할 수 밖에 없다. 
# 그렇다면 array value가 가장 큰곳(대나무가 가장 많은 곳)에서 부터 시작해서 대나무가 적은 곳으로 for문을 돌린다면,
# 0인 곳은 어차피 현재 위치보다 대나무가 적거나 같다는 뜻이 되므로, 이동할 수 없음을 의미하므로 Logic이 성립한다. 
# 만약 문제가 대나무가 같은 곳으로도 이동할 수 있었다면, 대나무가 같은 곳 끼리의 우선순위가 문제가 될 수 있겠다.
# 예시
# 1 3 2
# 4 3 4 
# 6 4 5
for y, x, val in b:
    d[y][x] = 1
    for k in range(4):
        ny, nx = y+dy[k], x+dx[k]
        if 0 <= ny < n and 0 <= nx < n:
            if a[y][x] < a[ny][nx]:
                d[y][x] = max(d[y][x], d[ny][nx] +1)
ans = 0
for i in range(n):
    ans = max(ans, max(d[i]))
print(ans)

