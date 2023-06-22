import sys
input = sys.stdin.readline

N = int(input())
count = 0
person = set()
for _ in range(N):
    s= input().strip()
    if s=='ENTER':
        person.clear()
    elif s not in person:
        person.add(s)
        count+=1

print(count)


