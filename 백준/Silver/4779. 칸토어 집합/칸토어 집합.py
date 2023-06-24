import sys


input = sys.stdin.readline




def kantorer(kan,len):
    if len == 1:
        print(kan,end='')
        return
    
    kantorer(kan[:len//3],len//3)
    kantorer(' '*(len//3),len//3)
    kantorer(kan[len//3*2:],len//3)

while True:
    try :
        N = int(input())
        kan = '-'
        for i in range(N):
            kan *= 3
        kantorer(kan,len(kan))
        print()
    except:
        break

