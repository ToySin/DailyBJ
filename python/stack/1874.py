import sys

def solution():
    N, *nums = map(int, sys.stdin.buffer.read().splitlines())

    seq = []
    ans = []
    cur = 1
    for num in nums:
        while num >= cur:
            ans.append(cur)
            cur += 1
            seq.append('+')

        if ans.pop() != num:
            return "NO"

        seq.append('-')
    return '\n'.join(seq)

print(solution())
