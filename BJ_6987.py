import sys

def Input_Data():
	n = map(int, readl().split())
	result = [[next(n) for w in range(3)] for t in range(6)]
	return result

def check():
    win, lose, draw, draw_count = 0, 0, 0, 0
    # test = [res[:] for res in range(len(result))]
    for match_result in result: 
        if sum(match_result) != 5: return False # 한 국가가 5번의 경기를 하지 않으면 잘못된 경기

        win += match_result[0]
        lose += match_result[2]
        draw += match_result[1]

    # print("win, lose, draw, draw_count: ", win, lose, draw, draw_count)
    if win != lose: return False #승수와 패배수가 같지 않으면 잘못된 경기
    if (draw % 2) == 1: return False # 무승부 개수가 홀수이면 잘못된 경기
    return True

def dfs(num):
    if num == len(match_game):
        # if test == result:
        return True
        # return False
    
    for i in range(3):
        if (test[match_game[num][0]][i] < 1) or (test[match_game[num][1]][2-i] < 1): continue
        test[match_game[num][0]][i] -= 1
        test[match_game[num][1]][2-i] -= 1
        if dfs(num+1): return True
        test[match_game[num][0]][i] += 1
        test[match_game[num][1]][2-i] += 1
    return False

readl = sys.stdin.readline
sol_list = []
for _ in range(4):
    result = Input_Data()
    test = [res[:] for res in result]
    # 0번국가 부터 5번 국가까지 모두 매칭해 보면 총 15가지 경우의 수가 나온다.
    match_game = ((0,1),(0,2),(0,3),(0,4),(0,5),(1,2),(1,3),(1,4),(1,5),(2,3),(2,4),(2,5),(3,4),(3,5),(4,5))

    if check() and dfs(0):
        sol_list.append(1)
    else:
        sol_list.append(0)

print(*sol_list)
