import sys

from itertools import permutations

input = sys.stdin.readline

N, M = map(int,input().split())

A = [list(map(int,input().split())) for _ in range(N)]

M, K = map(int, input().split())

B= [list(map(int, input().split())) for _ in range(M)]

C = [[0 for _ in range(K)] for _ in range(N)]

for i in range(N):
    for j in range(K):
        for n in range(M):
            C[i][j] += A[i][n] * B[n][j]


for i in C:
    for j in i:
        print(j, end = ' ')
    print()
