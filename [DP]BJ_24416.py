import sys

rdln = sys.stdin.readline

# def main():
def recur(n):
    global cnt1
    if (n ==1) or (n==2):
        cnt1 += 1
        return 1
    else:
        return recur(n-1) + recur(n-2)

def recur_dp(n):
    global cnt2
    f = [1]*(n+1)
    for i in range(3, n+1):
        cnt2 += 1
        f[i] = f[i-1] + f[i-2]
    return f[n]

n = int(rdln())
cnt1, cnt2 = 0, 0

recur(n)
recur_dp(n)
sys.stdout.write(f"{cnt1} {cnt2}")
