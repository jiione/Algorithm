import sys

from itertools import permutations




input = sys.stdin.readline


N = int(input())

arr = []
for i in range(N):
    arr.append(int(input()))

max = max(arr)

dp = [0]*101

dp[1] = 1
dp[2] = 1
dp[3] = 1
dp[4] = 2
dp[5] = 2
for i in range(6,max+1):
    dp[i] = dp[i-5] + dp[i-1]

for i in arr:
    print(dp[i])


