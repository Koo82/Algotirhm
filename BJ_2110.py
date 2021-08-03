import sys

N, C = map(int, sys.stdin.readline().split())
arr = [int(sys.stdin.readline()) for _ in range(N)]
arr = sorted(arr)
# print(arr)

def binary_search():
    L = 1
    R = arr[len(arr)-1]git  - arr[0]
    result = 1

    while L<=R:
        mid = (L+R)//2
        prev = arr[0]
        cnt = 1
        for i in range(1, len(arr)):
            if arr[i] - prev >= mid:
                cnt += 1
                prev = arr[i]

        if cnt >= C:
            result = max(result, mid)
            L = mid +1
        else:
            R = mid -1

    return result

sys.stdout.write(f"{binary_search()}")





