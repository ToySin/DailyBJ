# 순서대로 넣고 생존시간을 측정한다.
# 내가 생존할 수 없는 (현재 가격이 나보다 작은) 경우가 오면 pop 해서
# 생존 카운트를 증가시키지 않는다.

def solution(prices):
    answer = [0] * len(prices)
    s = []
    for i in range(len(prices)):

        # 햔제 스택에 있는 가격의 생존 시간 증가
        for e, idx in s:
            answer[idx] += 1

        # 현재 주식 가격보다 높은 예전의 기록 pop
        while s and s[-1][0] > prices[i]:
            s.pop()

        # 현재 주식 가격 push -> 적어도 한번은 +1 되게끔 한다.
        # 문제에서 다음 1초만에 바로 떨어져도 0초 생존이 아닌 1초 생존으로 취급
        s.append([prices[i], i])
    return answer
