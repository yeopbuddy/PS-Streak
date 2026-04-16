import sys
input = sys.stdin.readline

MOD = 1000000000

N, K = map(int, input().split())

size = N + K
dp = [[0] * (size + 1) for _ in range(size + 1)]

for i in range(size + 1):
    dp[i][0] = 1
    for j in range(1, i + 1):
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD

print(dp[N + K - 1][K - 1])