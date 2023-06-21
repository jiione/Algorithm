import sys
input = sys.stdin.readline

N = int(input())
word = [input().strip() for _ in range(N)]
word = list(set(word))
word.sort(key = lambda x:(len(x), x))

for i in word:
    print(i)
