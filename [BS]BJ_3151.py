import sys

rdln = sys.stdin.readline

def input_data():
    n = int(rdln())
    arr = list(map(int, rdln().split()))
    arr.sort()
    return n, arr

def solve():
    # two pointer method
    sol = 0
    for i in range(n-2):
        if arr[i]>0 : break
        l, r = i+1, n-1
        # print("i: ", i)
        while (l<r):
            _sum = arr[i]+arr[l]+arr[r]
            if _sum > 0:
                r -= 1
            elif _sum < 0:
                l += 1
            else: # 합이 0일 경우
                if arr[r] == arr[l]: # 정렬된 상태에서 두수가 같으면 사이값은 모두 같은 상태
                    sol += (r-l+1)*(r-l)//2 # (r-l+1)C2
                    break
                else: # 그렇지 않으면 l, r에서 하나씩 내려가면서 같은수의 갯수를 탐색
                    r_move, l_move = 0, 0
                    r_value = arr[r]
                    l_value = arr[l]
                    while arr[r] == r_value: # 한번은 무조건 카운팅 되야 한다.
                        r_move += 1
                        r -= 1
                    while arr[l] == l_value: # 마찬가지로 한번은 무조건 카운팅
                        l_move += 1
                        l += 1
                    sol += l_move*r_move # 조합의 갯수를 더해준다.
    return sol

n, arr = input_data()
sys.stdout.write(f"{solve()}")
