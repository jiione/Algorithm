h, m = map(int, input().split())
n = int(input())
m+=n
h+=m//60
m%=60
h%=24
print(h,m)