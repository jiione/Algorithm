import sys
input = sys.stdin.readline

N = int(input())

stack = []

for _ in range(N):
    num = int(input())
    if num == 0 :
        stack.pop()
    else:
        stack.append(num)

print(sum(stack))



