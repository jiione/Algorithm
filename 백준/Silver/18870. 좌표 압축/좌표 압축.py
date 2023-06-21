import sys
input = sys.stdin.readline

N = int(input())

num = list(map(int, input().split()))
sort_num = sorted(list(set(num)))
dic = {}
for i in range(len(sort_num)):
    dic[sort_num[i]]=i

for i in num:
    print(dic[i],end=' ')
