N = int(input())
result=N
for _ in range(N):
    s = input().lower()
    s_list = list(set(s))
    idx=0
    for i in range(len(s)-1):
        if s[i]==s[i+1]: pass
        elif s[i] in s[i+1:]:
            result-=1
            break

print(result)
        

