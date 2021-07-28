import sys
DEBUG = False
sys.setrecursionlimit(10**6)

def log(message):
    if DEBUG:
        print(message)


def dfs(v, color):
    global vertex_c, ans, t_num
    vertex_c[v] = color
    t_num += 1
    if t_num == V:
        return 0

    for v_t in map_g[v]:
        # log(v_t)
        if vertex_c[v_t] == -1:
            dfs(v_t, (color + 1) % 2)
        if vertex_c[v_t] == color:
            ans = "NO"
            return 0
    return 0


K = int(sys.stdin.readline())
for _ in range(K):
    V, E = map(int, sys.stdin.readline().split())
    map_g = [[] for _ in range(V+1)]
    vertex_c = [-1] * (V+1)
    log(("vertex_c", vertex_c))
    t_num = 0
    ans = "YES"

    # graph generation
    for _ in range(E):
        v1, v2 = map(int, sys.stdin.readline().split())
        map_g[v1].append(v2)
        map_g[v2].append(v1)
    log(("map_g", map_g))

    for v in range(1,V+1):
        # log(v)
        if vertex_c[v] == -1:
            dfs(v, 0)
    sys.stdout.write(f"{ans}\n")

