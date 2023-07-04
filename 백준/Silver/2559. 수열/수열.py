import sys

from itertools import permutations

input = sys.stdin.readline

n, k = map(int,input().split())

arr = list(map(int,input().split()))

for i in range(1,n):
    arr[i]+=arr[i-1]

arr.insert(0,0)

for i in range(n,k,-1):
    arr[i] -= arr[i-k]

arr2 = arr[k:]

print(max(arr2))