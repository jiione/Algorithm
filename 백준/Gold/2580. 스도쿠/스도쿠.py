import sys




input = sys.stdin.readline


def CheckBlank():
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                blank.append((i,j))

def check(value,x,y):
    if value in board[y]: return False

    for i in range(9):
        if value == board[i][x]: return False

    tX = (x//3)*3
    tY = (y//3)*3

    for i in range(3):
        for j in range(3):
            if value == board[tY+i][tX+j]: return False

    return True

def dfs(idx):
    global end
    if idx==len(blank):
        end=True
        for i in range(9):
            print(' '.join(map(str,board[i])))
    

    if end: return

    y=blank[idx][0]
    x=blank[idx][1]

    for i in range(1,10):
        if check(i,x,y)==True:
            board[y][x]=i
            dfs(idx+1)
            board[y][x]=0


end = False
board = [list(map(int,input().split())) for _ in range(9) ]
blank = []

CheckBlank()
dfs(0)

