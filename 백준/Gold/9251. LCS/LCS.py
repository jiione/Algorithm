import sys

from itertools import permutations

input = sys.stdin.readline

word1, word2= input().strip(),input().strip()

dp = [0]*len(word2)

for i in range(len(word1)):
    cnt = 0
    for j in range(len(word2)):
        if dp[j]>cnt:  cnt=dp[j]
        elif word1[i] == word2[j]:
            dp[j] = cnt+1

print(max(dp))
            