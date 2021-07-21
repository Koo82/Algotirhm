import sys
DEBUG = True


def log(message):
    if DEBUG:
        print(message)


row, col = map(int, sys.stdin.readline().split())
map_a = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(row)]
log(("map_a ", map_a))
max_v = 0

# max 2**16 = 65536 iteration
for c_s in range(1 << (row*col)):
    total_sum = 0
    sum = 0
    # left_right calculation
    for i in range(row):
        sum = 0
        for j in range(col):
            # location mapping col*i+j = bit masking map
            if c_s & (1 << col*i+j) == 0:
                sum *= 10
                sum += map_a[i][j]
            else:
                total_sum += sum
                sum = 0
        total_sum += sum
    # top-down calculation
    for k in range(col):
        sum = 0
        for l in range(row):
            if c_s & (1 << col * l + k):
                sum *= 10
                sum += map_a[l][k]
            else:
                total_sum += sum
                sum = 0
        total_sum += sum

    if total_sum > max_v:
        max_v = total_sum

sys.stdout.write(f"{max_v}")




