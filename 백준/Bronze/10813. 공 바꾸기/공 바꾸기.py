N,M = map(int,input().split())
basket = [ i for i in range(0,N+1)]

for _ in range(M):
    i,j = map(int, input().split())
    basket[i],basket[j] = basket[j],basket[i]
for i in range(1,N+1):
    print(basket[i],end=" ") 
