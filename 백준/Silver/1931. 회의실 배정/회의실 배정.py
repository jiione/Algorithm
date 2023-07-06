import sys

from itertools import permutations

input = sys.stdin.readline

N = int(input())

sche = []

for i in range(N):
    a,b = map(int, input().split())
    sche.append([a,b])

sche.sort(key= lambda x: (x[1],x[0]))

time = 0
cnt = 0

for i in sche:
    if time<=i[0]:
        cnt+=1
        time=i[1]

print(cnt)