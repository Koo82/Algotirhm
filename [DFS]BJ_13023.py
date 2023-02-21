import sys

rdln = sys.stdin.readline

def input_data():
    graph = {}
    n, m = map(int, rdln().split())
    for _ in range(m):
        a, b = map(int, rdln().split())
        if graph.get(a):
            graph[a].append(b)
        else:
            graph[a] = [b]
        
        if graph.get(b):
            graph[b].append(a)
        else:
            graph[b] = [a]
    return n, m, graph

def dfs(num, cnt):
    if cnt >= 4:
        return True
    # graph 내부로 바로 접근하므로, key error방지 필요
    # size로 접근하면 조건을 뺄 수 있음.
    if graph.get(num):
        for nex in graph[num]:
            if check[nex]: continue
            check[nex] = 1
            if dfs(nex, cnt +1): return True
            check[nex] = 0
    return False

n, m, graph = input_data()
sol = 0
for i in range(n):
    check = [0]*2000
    check[i] = 1
    if dfs(i, 0): 
        sol = 1
        break

sys.stdout.write(f"{sol}\n")


    
