# 누가 2등을 했냐?
# 매주 랭킹 리스트 -> 2등 선수 누구?

# 선수는 1~10000
# N주 동안 상위 M명의 정보

from collections import Counter

while True:
    N, M = map(int, input().split())

    if N == 0 and M == 0:
        break

    ct = Counter()
    for _ in range(N):
        line = list(map(int, input().split()))
        ct.update(line)

    # 2등 점수
    second_score = ct.most_common(2)[1][1]

    result = []
    for k, v in ct.items():
        if v == second_score:
            result.append(k)
    result = sorted(result)

    for n in result:
        print(n, end=' ')
    print()
