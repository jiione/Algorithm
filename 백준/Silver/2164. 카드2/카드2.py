import sys
from collections import deque
input = sys.stdin.readline

n= int(input())

queue = deque([i for i in range(1,n+1)])

while len(queue)>1:
    queue.popleft()
    card = queue.popleft()
    queue.append(card)

print(*queue)


