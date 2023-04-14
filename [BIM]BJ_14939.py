import sys

rdln = sys.stdin.readline

def input_data():
    arr = []
    for i in range(10):
        temp = rdln().rstrip()
        tval = 0
        for j in range(10):
            if temp[j] == 'O':
                tval += 2**j
        arr.append(tval)
    return arr

def check(a):
    for i in range(10):
        if a[i] != 0:
            return False
    return True

def light_on(t, y, x):
    t[y] = t[y]^(1<<x)
    if (y > 0): t[y-1] = t[y-1]^(1<<x)
    if (y < 9): t[y+1] = t[y+1]^(1<<x)
    if (x > 0): t[y] = t[y]^(1<<(x-1))
    if (x < 9): t[y] = t[y]^(1<<(x+1))

def solve():
    # 첫번째 행에 대해서 전구를 켤수 있는 경우의 수에 대해 전탐색을 진행하고
    # 이 후 열은 위의 열의 불을 끄는데 집중해서 진행한다. 아래에서 끄지 않으면 불을 끌 수 없기 때문에.
    ans = 200 # 똑같은 자리를 2번 누르는 것은 원래 상태로 돌아가기 때문에 낭비 행위, 대략 2배로 설정
    for bit in range(0, 1<<10):
        t_arr = arr.copy()
        cnt = 0
        # 첫번째 행에 대한 계산 먼저 수행, 모든
        for i in range(10):
            if bit & (1<<i):
                cnt += 1
                light_on(t_arr, 0, i)
        # 이후 계산은 이전 행에 켜져 있는 불을 끄면서 진행해야 한다.
        for y in range(1, 10): # 행에 대한 체크, 두 번째 행에서 부터 시작
            for x in range(0, 10): # 열에 대한 체크
                if (t_arr[y-1] & (1<<x)):
                    cnt += 1
                    light_on(t_arr, y, x)
        
        if check(t_arr): # 불이 다 꺼져 있는지 확인
            ans = min(ans, cnt)
    if ans == 200: # 방법이 없다면 -1을 출력
        return -1
    return ans 

arr = input_data()
# print(f"arr: {arr}")
t_arr = arr.copy()
# print(f"t_arr: {t_arr}")
# light_on(t_arr, 1, 1)
# light_on(t_arr, 4, 4)
# light_on(t_arr, 4, 5)
# light_on(t_arr, 8, 8)
# print(f"t_arr: {t_arr}")
sys.stdout.write(f"{solve()}\n")

