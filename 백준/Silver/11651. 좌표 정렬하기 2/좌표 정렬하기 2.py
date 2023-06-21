import sys
input = sys.stdin.readline

N = int(input())

list = []
for _ in range(N):
    a,b = map(int,input().split())
    list.append([a,b])

list = sorted(list, key = lambda x: (x[1],x[0]))

for i in list:
    print(*i)
