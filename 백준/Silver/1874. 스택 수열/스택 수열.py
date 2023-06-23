import sys
input = sys.stdin.readline

n= int(input())

num = 1

stack = []
log = []
for _ in range(n):
    n = int(input())
    while num <= n:
        stack.append(num)
        log.append('+')
        num+=1

    if stack[-1] == n:
        stack.pop()
        log.append('-')
    else :
        print('NO')
        break

else:
    for i in log:
        print(i)



