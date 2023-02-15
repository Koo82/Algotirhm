import sys

rdln = sys.stdin.readline

def input_data():
    n, m = map(int, rdln().split())
    t_map = []
    for i in range(n):
        temp = rdln().strip()
        a = []
        for val in temp:
            # 'W'를 1값으로, 'B'를 0으로 계산
            if val == 'W':
                a.append(1)
            else:
                a.append(0)
        t_map.append(a)

    return n, m, t_map

def brute_force():
    ans = 100
    for i in range(n-8+1):
        for j in range(m-8+1):
            # 체스판 시작 위치에서의 값 'W'또는 'B'
            for p in range(2):
                cnt = 0
                # 8행, 8열 체스판 완전 탐색
                for k in range(8):
                    for l in range(8):
                        # 체스판 시작 위치에서의 값p를 기준으로 
                        # l열, k행만큼 진행할 경우의 예상값 계산 ((p + l) + k) % 2
                        # 값이 맞으면 skip, 아니면 cnt에 1더해줌
                        if t_map[i+k][j+l] == ((p + l) + k) % 2: continue
                        cnt += 1
                # print("cnt: " cnt)
                ans = min(ans, cnt)
    return ans

n, m, t_map = input_data()
# print("t_map: ", t_map)

sol = brute_force()
sys.stdout.write(f"{sol}\n")
