# 문제를 보자마자, 분할 정복임을 깨달았다.
# 문제는 어떻게 구현하느냐.
# 검색하여 확인한 방법은 이와 같음
# 임의의 맵 크기의 (1,1) 요소만 empty space를 유지하고,
# 나머지는 별을 찍어주면 된다. 다만, 요소 하나당 분할정복으로 풀고
# 이를 2개의 for loop으로 반복하면 종료 3^7 = 2,187
# 결과 : 시간 초과  - > python의 비효율성 때문?

# 좀더 효율적일 수 있게 한줄 단위로 체크할 수 있게 만들어 보자.

import sys
DEBUG = True


def log(message):
    if DEBUG:
        print(message)


def print_star(base_m):
    star_map = []
    for i in range(3*len(base_m)):
        if i // len(base_m) == 1:
            star_map.append(base_m[i%len(base_m)] + ' '*len(base_m) + base_m[i%len(base_m)])
        else:
            star_map.append(base_m[i%len(base_m)] * 3)
    return star_map

N = int(sys.stdin.readline())
base_m = ["***", "* *", "***"]
rep = 0

while N != 3:
    N /= 3
    rep += 1

for i in range(rep):
    base_m = print_star(base_m)


for j in base_m:
    sys.stdout.write(f"{j}\n")




# def splitW(y, x, size):
#     if ((y // size) % 3 == 1) and ((x // size) % 3 == 1):
#         sys.stdout.write(' ')
#     else:
#         if size // 3 == 0:
#             sys.stdout.write('*')
#         else:
#             splitW(y,x,size/3)
#
# for y in range(N):
#     for x in range(N):
#         splitW(y,x,N)
#     sys.stdout.write('\n')