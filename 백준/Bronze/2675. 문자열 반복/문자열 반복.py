N = int(input())

for _ in range(N):
    T, S = input().split()
    text=""
    for i in range(len(S)):
        text+=S[i]*int(T)
    print(text)
