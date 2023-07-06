import sys

from itertools import permutations

input = sys.stdin.readline

N,K = map(int,input().split())

arr = []

for i in range(N):
    arr.append(int(input()))

arr.reverse()

cnt = 0
idx = 0

while K!=0:
    cnt+=K//arr[idx]
    K%=arr[idx]
    idx+=1

print(cnt)




