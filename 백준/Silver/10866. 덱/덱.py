import sys
from collections import deque


input = sys.stdin.readline
num = int(input())

queue = deque()

for _ in range(num):
    cmd = input().rstrip().split()

    if cmd[0] == 'push_front': queue.appendleft(int(cmd[1]))
    elif cmd[0] =='push_back': queue.append(int(cmd[1]))
    elif cmd[0] =='pop_front':
        if len(queue)>0 :
            x=queue.popleft()
            print(x)
        else: print(-1)
    elif cmd[0] =='pop_back':
        if len(queue)>0 :
            x=queue.pop()
            print(x)
        else: print(-1)
    elif cmd[0] =='size': print(len(queue))
    elif cmd[0] =='empty':
        if len(queue)>0 : print(0)
        else: print(1)
    elif cmd[0] =='front':
        if len(queue)>0: print(queue[0])
        else: print(-1)
    elif cmd[0] =='back':
        if len(queue)>0: print(queue[-1])
        else: print(-1)


