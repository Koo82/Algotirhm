# 세가지 합을 구해야 하는 상황이기 때문에, 두개의 합을 구한 것과
# 나머지 하나의 작은 합을 구해 나가면 될 것 같은데,
# 문제는 두개의 용액을 합한 것과 나머지 하나의 인덱스가 겹치는 경우다
# 이를 위해 dict를 사용하면 인덱스 중첩을 피할 수 있지 않을까?
# [결과] 메모리 초과, 아마도 dict의 용량이 너무 큰가 보다
# 어차피 O(n2)이라면, 하나를 고정해서 더하고 나머지 2개의 수에 두 포인터를 적용해 본다! 성공!!

import sys
from math import inf
DEBUG = True


def log(message):
    if DEBUG:
        print(message)


N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort()
log(("arr: ", arr))

ans = inf
mem = []

for i in range(1, N-1):
    arr_1 = arr[:i]; arr_2 = arr[(i+1):]
    low = 0; high = N-1
    while 1:
        if low == i or high == i:
            break
        sum_temp = arr[i] + arr[low] + arr[high]
        if abs(sum_temp) < abs(ans):
            ans = sum_temp
            mem = [arr[low], arr[i], arr[high]]
        if sum_temp < 0:
            low += 1
        else:
            high -= 1

sys.stdout.write(f"{mem[0]} {mem[1]} {mem[2]}")






# arr_2 = []
# index_checker = dict()
# for i in range(N):
#     for j in range(i+1,N):
#         arr_2.append(arr[i]+arr[j])
#         index_checker[arr[i]+arr[j]] = [arr[i], arr[j]]
#
# arr.sort()
# arr_2.sort()
# log(("arr: ", arr))
# log(("arr_2: ", arr_2))
# log(("index_checker: ", index_checker))
#
# low = 0; high = len(arr_2)-1; ans = inf
# while 1:
#     if low == len(arr) or high == -1:
#         break
#     sum_temp = arr[low] + arr_2[high]
#     if arr[low] not in index_checker[arr_2[high]]:
#         if abs(sum_temp) < abs(ans):
#             ans = sum_temp
#             mem = [arr[low]] + index_checker[arr_2[high]]
#
#     if sum_temp < 0:
#         low += 1
#     else:
#         high -= 1
#
# mem.sort()
# sys.stdout.write(f"{mem[0]} {mem[1]} {mem[2]}")



