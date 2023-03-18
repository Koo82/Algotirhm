import sys
from collections import deque

rdln = sys.stdin.readline
dy, dx = [-1, 0, 1, 0], [0, -1, 0, 1]

def input_data():
    n = int(rdln())
    arr = [list(map(int, rdln().split())) for _ in range(n)]
    return n, arr

def bfs():
    cat = 1
    sol = 10_000
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 1: # arr[i][j] == 0이면 바다 이므로 skip
                cat += 1 # 섬번호 category
                q1 = deque([(i,j)]) # 현재 섬의 영역 확인
                q2 = deque([(0,i,j)]) # 다른 섬과의 거리를 확인 하기 위한 queue
                arr[i][j] = cat # 현재 섬번호 저장
                while q1: # 현재 섬 영역 확인 및 다른섬과의 거리 0으로 초기화
                    y, x = q1.popleft()
                    for k in range(4):
                        ny, nx = y + dy[k], x + dx[k]
                        if not (0<=ny<n and 0<=nx<n): continue
                        if arr[ny][nx] != 1: continue
                        q1.append((ny, nx))
                        q2.append((0, ny, nx))
                        arr[ny][nx] = cat
                
                check = [[0]*100 for _ in range(100)] # visit 배열
                flag = False
                while q2: # 현재 섬에서 다른 섬으로의 거리 파악 
                    cost, y, x = q2.popleft()
                    # check[y][x] = 1
                    if flag or (cost >= sol):
                        break
                    for k in range(4):
                        ny, nx = y + dy[k], x + dx[k]
                        if not (0<=ny<n and 0<=nx<n): continue
                        if check[ny][nx]: continue
                        if arr[ny][nx] != 0:
                            if arr[ny][nx] != cat: 
                                sol = min(sol, cost)
                                flag = True
                                break
                            else:
                                continue
                        q2.append((cost+1, ny, nx))
                        check[ny][nx] = 1
    return sol

n, arr = input_data()
sys.stdout.write(f"{bfs()}\n")
