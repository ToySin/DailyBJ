import sys
input = sys.stdin.readline

s = []

n = int(input())

for _ in range(n):
    op = input().rstrip()
    if op == "pop":
        print(s.pop() if s else -1)
    elif op == "size":
        print(len(s))
    elif op == "empty":
        print(0 if s else 1)
    elif op == "top":
        print(s[-1] if s else -1)
    else:
        _, x = op.split()
        s.append(x)
