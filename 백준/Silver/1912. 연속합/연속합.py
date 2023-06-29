import sys

from itertools import permutations




input = sys.stdin.readline


N = int(input())

dp = list(map(int, input().split()))

for i in range(1,N):
    dp[i]=max(dp[i],dp[i]+dp[i-1])

print(max(dp))

