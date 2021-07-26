import sys
DEBUG = True


def log(message):
    if DEBUG:
        print(message)

def f(i,j):
    return col*i + j

def dfs(v):
    if check[v]:
        return 0
    check[v] = 1
    for c in g[v]:
        if par[c] == -1 or dfs(par[c]):
            par[c] = v
            return 1

    return 0


C = int(sys.stdin.readline())
idy = [-1, -1, 0, 0, 1, 1]
idx = [-1, 1, -1, 1, -1, 1]

for _ in range(C):
    row, col = map(int, sys.stdin.readline().split())
    arr = [list(sys.stdin.readline().rstrip()) for _ in range(row)]
    log(("arr : ", arr))
    # check = [[0] * col]* row
    # check = [0] * col * row
    # log(("check : ", check))
    par = [-1] * col * row
    g = [[] for _ in range(col * row)]
    sum_a = 0

    # no sitting position = 1, possible sitting position = 0
    for i in range(row):
        for j in range(col):
            if arr[i][j] == 'x':
                arr[i][j] = 1
            else:
                arr[i][j] = 0
                sum_a += 1
    log(("After array : ", arr))

    # bipartite graph representation
    for i in range(row):
        for j in range(col):
            if arr[i][j]:
                continue
            for k in range(6):
                n_y = i + idy[k]
                n_x = j + idx[k]
                if (0 <= n_y <row) and (0 <= n_x <col):
                    if arr[n_y][n_x]:
                        continue
                    g[f(i,j)].append(f(n_y,n_x))
    log(("g array is : ", g))
    log(("Before par : ", par))
    # minimum vertex cover == bipartite matching
    # Maximum independent set == total - mimimum vertex cover
    ans = 0
    for i in range(row):
        for j in range(0, col, 2):
            if arr[i][j]:
                continue
            # bipartite matching 전에 check 배열 초기화
            check = [0] * col * row
            ans += dfs(f(i,j))

    # log(("After par : ", par))
    # nvc = 0
    # for i in range(row):
    #     for j in range(col):
    #         if par[f(i,j)] != -1:
    #             nvc += 1

    sys.stdout.write(f"{sum_a-ans}\n")








