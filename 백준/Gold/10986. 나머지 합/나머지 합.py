import sys

from itertools import permutations

input = sys.stdin.readline

n, m = map(int,input().split())

arr = list(map(int,input().split()))

arr[0]%=m
arr2 = [0]*m

arr2[arr[0]]+=1

for i in range(1,n):
    arr[i]+=arr[i-1]
    arr[i]%=m
    arr2[arr[i]]+=1


cnt = arr2[0]
for i in arr2:
    num = i
    cnt += num*(num-1)//2

print(cnt)