N = list()
for i in range(9):
    N.append(int(input()))

print(max(N))
print(N.index(max(N))+1)