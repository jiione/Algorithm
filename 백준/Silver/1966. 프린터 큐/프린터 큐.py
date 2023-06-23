import sys
from collections import deque



num = int(input())

for _ in range(num):
    N,K = map(int, input().split())
    queue = deque(map(int,input().split()))
    check = queue[K]
    queue[K] = -1
    cnt = 1

    while True:
        if check >= max(queue) and queue[0] == -1:
            break
        elif queue[0] == max(queue) and queue[0]>=check:
            queue.popleft()
            cnt+=1
        else:
            queue.append(queue.popleft())
    print(cnt)


