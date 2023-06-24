import sys
from collections import deque


input = sys.stdin.readline

T = int(input())

for _ in range(T):
    cmd = input().rstrip()
    N = int(input())
    arr = deque(input().rstrip()[1:-1].split(','))

    rev = 0
    for i in cmd:
        if i == 'R':
            rev+=1
        elif i == 'D' and arr and N!=0:
            if rev%2 == 1:
                arr.pop()
            else:
                arr.popleft()
        else:
            print('error')
            break

    else:
        if rev % 2 == 1: arr.reverse()
        print('['+','.join(arr)+']')
