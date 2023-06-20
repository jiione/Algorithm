arr = [list(map(int,input().split())) for _ in range(9)]
idx = [0,0]
max = 0
for i in range(9):
    for j in range(9):
        if max <= arr[i][j]:
            max= arr[i][j]
            idx = [i+1,j+1]
print(max)
print(*idx)
        

