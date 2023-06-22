import sys
input = sys.stdin.readline

N = int(input())


for _ in range(N):
    stack = []
    s = input().strip()
    for i in s:
        if i == '(': stack.append(i)
        elif i ==')' and stack:
            stack.pop()
        else:
            print('NO')
            break
    else:
        if not stack: print('YES')
        else: print('NO')
        



