import sys
input = sys.stdin.readline

N = int(input())

list = []
for _ in range(N):
    a,b = map(int,input().split())
    list.append([a,b])

list = sorted(list)

for i in list:
    print(*i)
