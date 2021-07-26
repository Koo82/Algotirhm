import sys
DEBUG=True


def log(message):
    if DEBUG:
        print(message)

def dfs(cow_num):
    if visit[cow_num]:
        return False
    visit[cow_num] = True

    for house_num in cow_w[cow_num]:
        if house_a[house_num] == 0 or dfs(house_a[house_num]):
            house_a[house_num] = cow_num
            return True
    return False

cow, house = map(int, sys.stdin.readline().split())
# 소가 원하는 house number 저장 배열, 소의 번호는 1번 부터 시작
cow_w = [0] + [list(map(int, sys.stdin.readline().rstrip().split()))[1:] for _ in range(cow)]
house_a = [0 for _ in range(house+1)]

log(("cow_w", cow_w))

for cow_num in range(1, cow+1):
    # visit array to prevent dfs running forever
    visit = [False] * (cow+1)
    dfs(cow_num)

ans = len(house_a) - house_a.count(0)
sys.stdout.write(f"{ans}\n")
