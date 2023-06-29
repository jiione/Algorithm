import sys

from itertools import permutations




input = sys.stdin.readline


N = int(input())

dp=[]
for i in range(N):
    dp.append(list(map(int,input().split())))


for i in range(N-1,0,-1):
    for j in range(len(dp[i])-1):
        dp[i-1][j] += max(dp[i][j], dp[i][j+1])


print(dp[0][0])

