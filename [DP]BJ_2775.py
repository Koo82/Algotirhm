import sys

rdln = sys.stdin.readline

def input_data():
    t = int(rdln())
    flr, room = [], []
    for _ in range(t):
        flr.append(int(rdln()))
        room.append(int(rdln()))
    return t, flr, room

def solve():
    dp = [[0]*15 for _ in range(15)]
    sol = []
    for i in range(1, 15): # 0층 초기값 설정
        dp[0][i] = i
    
    for i in range(1, 15): # 1층부터
        for j in range(1, 15): # 1호부터
            dp[i][j] = dp[i][j-1] + dp[i-1][j] # 점화식 전개
    
    for i in range(t): # 저장된 dp 배열에서 층, 호의 값을 호출
        sol.append(dp[flr[i]][room[i]])
    return sol

t, flr, room = input_data()
sol = solve()

for val in sol:
    sys.stdout.write(f"{val}\n")

