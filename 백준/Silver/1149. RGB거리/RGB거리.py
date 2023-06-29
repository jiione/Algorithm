import sys

from itertools import permutations




input = sys.stdin.readline


dp = [[0, 0, 0] for _ in range(1001)]

N = int(input())

for i in range(1,N+1):
    r,g,b = map(int, input().split())
    dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + r
    dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + g
    dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + b


print(min(dp[N][0],dp[N][1],dp[N][2]))

