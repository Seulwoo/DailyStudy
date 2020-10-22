import sys
read = sys.stdin.readline
N = int(read())

dp = [[0 for _ in range(10)] for _ in range(1001)] // dp[1001][10]의 
for t in range(10):
    dp[1][t] = 1
for i in range(2, N+1):
    for t in range(10):
        for p in range(t, 10):
            dp[i][t] += dp[i-1][p]
        dp[i][t] %= 10007

answer = 0
for t in range(10):
    answer += dp[N][t]

print(answer%10007)
