import sys

def dfs(ma):
    if visited[ma]:
        return False
    visited[ma] = True

    for wor in man_c[ma]:
        if work_a[wor] == 0 or dfs(work_a[wor]):
            work_a[wor] = ma
            return True
    return False

man, work = map(int, sys.stdin.readline().split())
man_c = [0] + [list(map(int, sys.stdin.readline().rstrip().split()))[1:] for _ in range(man)]
work_a = [0] * (work+1)

for i in range(1, man+1):
    visited = [0] * (man+1)
    dfs(i)

ans = len(work_a) - work_a.count(0)
sys.stdout.write(f"{ans}\n")