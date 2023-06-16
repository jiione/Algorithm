A = int(input())
B = int(input())
C=B
print(A*(C%10))
C//=10
print(A*(C%10))
C//=10
print(A*(C%10))
print(A*B)