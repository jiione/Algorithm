N, M = map(int,input().split())
A=[]
for i in range(N):
    A.append(list((input().split())))

for i in range(N):
    B=(input().split())
    for j in range(M):
        print(int(A[i][j])+int(B[j]),end=' ')
    print()

