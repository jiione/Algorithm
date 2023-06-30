import sys

from itertools import permutations

input = sys.stdin.readline


N = int(input())


dp1 = [1] * 1001
dp2 = [1] * 1001


arr= list(map(int,input().split()))

for i in range(1,N):
    for j in range(0,i):
        if arr[j]<arr[i]:
            dp1[i] = max(dp1[j]+1, dp1[i])

for i in range(N-2,-1,-1):
    for j in range(N-1,i,-1):
        if arr[j]<arr[i]:
            dp2[i] = max(dp2[j]+1,dp2[i])

for i in range(0,N):
    dp1[i]+=dp2[i]-1




print(max(dp1))

