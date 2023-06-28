import sys

from itertools import permutations




input = sys.stdin.readline


N = int(input())

dp = []

dp.append(1)
dp.append(2)
for i in range(2,N):
    dp.append((dp[i-2]+dp[i-1])%15746)

print(dp[N-1])


