import sys
from collections import defaultdict, deque

DEBUG = True


def log(message):
    if DEBUG:
        print(message)


def topologicalsort():
    queue = deque()
    for i in range(1, N+1):
        if DOF[i] == 0:
            queue.append(i)
    result = []
    while queue:
        node = queue.popleft()
        result.append(node)
        for i in graph[node]:
            DOF[i] -= 1
            if DOF[i] == 0:
                queue.append(i)

    if len(result) != N:
        return [0]
    return result


N, M = map(int, sys.stdin.readline().split())
graph = defaultdict(list)
DOF = [0] * (N+1)

for _ in range(M):
    t_list = list(map(int, sys.stdin.readline().split()))
    for i in range(1,t_list[0]):
        graph[t_list[i]].append(t_list[i+1])
        DOF[t_list[i+1]] += 1

log(graph)
# log(topologicalsort())

for it in topologicalsort():
    sys.stdout.write(f"{it}\n")