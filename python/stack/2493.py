import sys
input = sys.stdin.readline

def solution():
    N = int(input())
    s = []

    towers = list(map(int, input().split()))
    towers = [(t, i) for t, i in zip(towers, range(1, N + 1))]
    for t in towers:
        while s and s[-1][0] < t[0]:
            s.pop()
        print(s[-1][1] if s else 0)
        s.append(t)

solution()
