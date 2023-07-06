import sys

from itertools import permutations

input = sys.stdin.readline

N = int(input())

person = list(map(int,input().split()))

person.sort()
result = 0

for i in range(N):
    result+=person[i]*(N-i)

print(result)