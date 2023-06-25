import sys


input = sys.stdin.readline

N = int(input())

def hanoi(N, start, end, tmp):
    if N == 1:
        print(start, end)
        return

    hanoi(N-1,start,tmp,end)
    print(start,end)
    hanoi(N-1,tmp,end,start)



print(2**N-1)
hanoi(N,1,3,2)