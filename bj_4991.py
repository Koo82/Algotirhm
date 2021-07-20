import sys
from collections import deque

DEBUG = True
def log(message):
    if DEBUG:
        print(message)

# "left, down, right, up" index for add
idx, idy = [-1,0,1,0], [0,-1,0, 1]

def bfs(i, j, move, stage):
    check = 1 # if check == 1, no solution
    deq = deque()
    deq.append((i,j, move, stage)) # y_index, x_index, move count, stage for * bit masking
    visited[stage][i][j] = False

    while deq:
        y, x, move, stage = deq.popleft()
        # log((y,x,move,stage))
        # if all stage is visited, then bit masking is (1 <<target) -1, that is exit solution
        if stage == (1 << target) -1 :
            sys.stdout.write(f"{move}\n")
            check = 0
            break
        # log(deq)
        for k in range(4):
            x_new = x + idx[k]
            y_new = y + idy[k]
            # log((y_new, x_new, move, stage))

            if 0<=x_new <w and 0<= y_new<h and visited[stage][y_new][x_new]:
                visited[stage][y_new][x_new] = False
                # -1 일 경우, 장애물이 있어서 전진 불가 skip처리
                if map_m[y_new][x_new] == -1:
                    continue
                # stage이고, bit masking으로 방문하지 않은 곳을 확인하면 bit masking 추가하여 큐에 저장
                if map_m[y_new][x_new] and not stage & (1 << (map_m[y_new][x_new]-1)):
                    deq.append((y_new, x_new, move+1, stage | (1 << (map_m[y_new][x_new]-1))))
                # 그렇지 않으면 ( stage가 아니거나, 이미 방문했다면 그냥 move +1 처리하고 큐에 추가
                else:
                    deq.append((y_new, x_new, move+1, stage))

    if check:
        sys.stdout.write(f"-1\n")

while True:
    w, h = map(int, sys.stdin.readline().split())
    if w == 0 and h == 0:
        break

    map_m = [list(sys.stdin.readline().rstrip()) for _ in range(h)]
    target = 0
    origin = (0,0)
    # bfs 탐색을 위한 전처리, 'o'의 경우는 출발 위치 저장 그리고 0으로 setting, 별은 순서대로 1~10까지 번호
    # 'x'는 방문이 어려우므로 -1처리 해준다
    for i in range(h):
        for j in range(w):
            if map_m[i][j] == 'o':
                origin = (i, j)
                map_m[i][j] = 0
            elif map_m[i][j] == '*':
                target += 1
                map_m[i][j] = target
            elif map_m[i][j] == "x":
                map_m[i][j] = -1
            else:
                map_m[i][j] = 0

    log(("origin", origin))
    log(('target number', target))

    visited = [[[True] * w for _ in range(h)] for _ in range(1 << (target+1))]

    log(("visited", visited))
    log(("changed map is ", map_m))
    bfs(origin[0], origin[1], 0, 0)


