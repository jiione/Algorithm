import sys
input = sys.stdin.readline

N = int(input())

person = []

for i in range(N):
    A, B = input().strip().split()
    person.append([A,B])

person = sorted(person,key=lambda x: int(x[0]) )

for i in person:
    print(i[0],i[1])
