import sys

from itertools import permutations

input = sys.stdin.readline

s= input().rstrip()

result = 0
sum = 0
word = ""
flag = 0
for i in s:
    if i == '+':
        sum+=int(word)
        word=""
    elif i == '-':
        sum+=int(word)
        if flag == 1: result-=sum
        else: result+=sum
        flag=1
        sum=0
        word=""
    else: word+=i

if flag==1:
    result-=(sum+int(word))
else:
    result+=(sum+int(word))

print(result)
