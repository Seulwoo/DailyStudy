import sys
sys.setrecursionlimit(100000) // 파이썬에서 재귀를 쓰려면 이게 필요하다고 한다!
read = sys.stdin.readline

N = int(read())
picture = []
for i in range(N):
    tmp = read()
    row = []
    for j in range(N):
        row.append(tmp[j])
    picture.append(row)

visit = [ [0 for _ in range(N) ] for _ in range(N)]
cnt_a = 0
cnt_b = 0
move_i = [0, 0, -1, 1]
move_j = [-1, 1, 0, 0]

def dfs_first(i, j):
    visit[i][j] = 1
    for d in range(4):
        new_i = i + move_i[d]
        new_j = j + move_j[d]
        if new_i < 0 or new_i > N-1 or new_j < 0 or new_j > N-1:
            continue
        if visit[new_i][new_j] == 1:
            continue
        if picture[i][j] == picture[new_i][new_j]:
            dfs_first(new_i, new_j)

def dfs_second(i, j):
    visit[i][j] = 1
    for d in range(4):
        new_i = i + move_i[d]
        new_j = j + move_j[d]
        if new_i < 0 or new_i > N-1 or new_j < 0 or new_j > N-1:
            continue
        if visit[new_i][new_j] == 1:
            continue
        if picture[i][j] == 'B' and picture[new_i][new_j] == 'B':
            dfs_second(new_i, new_j)
        elif picture[i][j] != 'B' and picture[new_i][new_j] != 'B':
            dfs_second(new_i, new_j)

for i in range(N):
    for j in range(N):
        if visit[i][j] == 0:
            dfs_first(i, j)
            cnt_a += 1
visit = [ [0 for _ in range(N) ] for _ in range(N)]
for i in range(N):
    for j in range(N):
        if visit[i][j] == 0:
            dfs_second(i, j)
            cnt_b += 1
print(cnt_a, cnt_b)
