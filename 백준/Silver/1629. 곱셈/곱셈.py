a, b, c = map(int, input().split(' '))


def dnc(length):
    if length == 1:
        return a % c
    left = dnc(length // 2)
    if length % 2 == 0:
        return left * left % c
    else:
        return left * left * a % c


print(dnc(b))