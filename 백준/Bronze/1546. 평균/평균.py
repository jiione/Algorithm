N = int(input())
score = list(map(int,input().split()))
max = max(score)
for i in range(N):
    score[i] = score[i]/max*100
print(sum(score)/len(score))