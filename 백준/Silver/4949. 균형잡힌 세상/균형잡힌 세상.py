import sys
input = sys.stdin.readline



while True:
    stack = []
    sentence = input().rstrip()
    if sentence == '.' :
        break

    for i in sentence:
        if i == '(' or i == '[': stack.append(i)
        elif i == ')':
            if stack and stack[-1] == '(': stack.pop()
            else : 
                print('no')
                break
        elif i == ']' :
            if stack and stack[-1] == '[' : stack.pop()
            else : 
                print('no')
                break

    else: 
        if not stack : print('yes')
        else : print('no')
        



