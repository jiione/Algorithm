import sys

from itertools import permutations

input = sys.stdin.readline

n, m = map(int,input().split())

arr = list(map(int,input().split()))

for i in range(1,n):
    arr[i]+=arr[i-1]

arr.insert(0,0)

for i in range(m):
    a,b = map(int, input().split())
    print(arr[b]-arr[a-1])