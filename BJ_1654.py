import sys
DEBUG = True


def log(message):
    if DEBUG:
        print(message)


K, N = map(int, sys.stdin.readline().split())
lan = [int(sys.stdin.readline()) for _ in range(K)]

log(lan)
def binary_search(num):
    left = 1
    right = max(lan)
    ans = 0

    while left <= right:
        collect = 0
        next_div = (left + right) // 2
        for i in lan:
            if i >= next_div:
                collect += (i // next_div)

        if collect >= num:
            ans = next_div
            left = next_div + 1
        else:
            right = next_div - 1

    return ans

sys.stdout.write(f"{binary_search(N)}")



