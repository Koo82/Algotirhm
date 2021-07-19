import sys
from collections import deque

DEBUG = True
def log(message):
    if DEBUG:
        print(message)

idx, idy = [-1,0,1,0], [0,-1,0, 1]
# w = sys.stdin.readline()

def bfs(i, j, move, stage):

    deq = deque()
    deq.append((i,j, move))
    visited[stage][i][j] = False
    map_m[i][j] = '.'
    while (deq and stage < target):
        y, x, move = deq.popleft()
        for k in range(4):
            x_new = x + idx[k]
            y_new = y + idy[k]
            if 0<=x_new <w and 0<= y_new<h and visited[stage][y_new][x_new]:
                visited[stage][y_new][x_new] = False
                if map_m[y_new][x_new] == '*':
                    stage += 1
                    visited[stage][y_new][x_new] = False
                    map_m[y_new][x_new] = '.'
                    deq.clear()
                    deq.append((y_new, x_new, move+1))
                    break
                elif map_m[y_new][x_new] == '.':
                    deq.append((y_new, x_new, move+1))

    return move, stage

while True:
    w, h = map(int, sys.stdin.readline().split())
    if w == 0 and h == 0:
        break
# log(w)
    map_m = [list(sys.stdin.readline().rstrip()) for _ in range(h)]
    target = 0
    origin = (0,0)
    for i in range(h):
        for j in range(w):
            if map_m[i][j] == 'o':
                origin = (i, j)
            elif map_m[i][j] == '*':
                target += 1

    log(("origin", origin))
    log(('target number', target))

    visited = [[[True] * w for _ in range(h)] for _ in range(target+1)]

    log(("visited", visited))

    m, s = bfs(origin[0], origin[1], 0, 0)
    if s == target:
        sys.stdout.write(f"{m+1}\n")
    elif target == 0:
        sys.stdout.write(f"0\n")
    else:
        sys.stdout.write(f"-1\n")

