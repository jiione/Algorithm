N ,M = map(int, input().split())
basket = [i for i in range(0,N+1)]

for _ in range(M):
    i,j = map(int,input().split())
    basket[i:j+1] = reversed(basket[i:j+1])

del basket[0]
print(*basket)