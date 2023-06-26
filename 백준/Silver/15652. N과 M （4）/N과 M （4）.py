import sys




input = sys.stdin.readline


N, M = map(int,input().split())

stack = []

def dfs(start):
    if len(stack) == M:
         print(*stack)
         return

    for i in range(start,N+1):
            stack.append(i)
            dfs(i)
            stack.pop()


dfs(1)

