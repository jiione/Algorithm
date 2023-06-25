import sys




input = sys.stdin.readline


N, M = map(int,input().split())

stack = []
visited = [0 for i in range(N+1)]

def dfs():
    if len(stack) == M: print(*stack)

    for i in range(1,N+1):
        if visited[i]==0:
            visited[i]=1
            stack.append(i)
            dfs()
            visited[i]=0
            stack.pop()


dfs()

