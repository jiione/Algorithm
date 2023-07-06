import sys

from itertools import permutations

input = sys.stdin.readline

N = int(input())

board = [list(map(int,input().rstrip())) for i in range(N)]
result =""
def divide(x,y,n):
    global result
    check = board[y][x]

    for i in range(y,y+n):
        for j in range(x,x+n):
            if check!=board[i][j]:
                check = -1
                break

    if check == -1:
        result+='('
        n//=2
        divide(x,y,n)
        divide(x+n,y,n)
        divide(x,y+n,n)
        divide(x+n,y+n,n)
        result+=')'
    elif check == 1:
        result+='1'
    else:
        result+='0'

divide(0,0,N)
print(result)


