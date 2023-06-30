import sys

from itertools import permutations

input = sys.stdin.readline


N = int(input())

arr=[0] * 10001

dp = [0] * 10001

for i in range(1,N+1):
    arr[i] = int(input())

dp[1] = arr[1]
dp[2] = arr[1] + arr[2]
for i in range(3,N+1):
    dp[i] = max(arr[i] + dp[i-2],arr[i]+arr[i-1] + dp[i-3],dp[i-1])

print(dp[N])

