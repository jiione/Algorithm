import sys

from itertools import permutations

input = sys.stdin.readline

N = int(input())

board = [list(map(int,input().split())) for i in range(N)]

zero = 0
one = 0
minus = 0
def divide(x,y,n):
    global zero,one,minus
    check = board[y][x]
    for i in range(y,y+n):
        for j in range(x,x+n):
            if board[i][j] != check:
                check = -2
                break

    if check == -2:
        n//=3
        divide(x,y,n)
        divide(x+n,y,n)
        divide(x+2*n,y,n)
        divide(x,y+n,n)
        divide(x+n,y+n,n)
        divide(x+n*2,y+n,n)
        divide(x,y+n*2,n)
        divide(x+n,y+n*2,n)
        divide(x+n*2,y+n*2,n)
    elif check == -1: minus +=1
    elif check == 0: zero +=1
    else: one +=1

divide(0,0,N)
print(minus)
print(zero)
print(one)
    
