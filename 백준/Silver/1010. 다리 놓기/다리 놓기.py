import sys
input = sys.stdin.readline

def factorial(start, end):
    result = 1

    for i in range(start,end+1):
        result*=i

    return result

N = int(input())

for _ in range(N):
    x, y = map(int, input().split())
    a=factorial(y-x+1, y)
    b=factorial(1,x)
    print(a//b)

