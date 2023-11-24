# 최종 목표 -> 가장 어려운 문제의 알고력 코딩력에 도달하기
# 순간순간의 선택
# 1. 1시간 공부로 알고력 or 코딩력 1 올리기
# 2. 풀수있는 문제 풀고 리워드만큼 알고력 코딩력 올리기

# 세로축 알고력, 가로축 코딩력으로 설정

INF = int(1e9)

def solution(alp, cop, problems):
    # 목표치 설정
    goal_alp = max(alp, max(map(lambda x: x[0], problems)))
    goal_cop = max(cop, max(map(lambda x: x[1], problems)))

    # dp 생성 및 시작 능력치는 필요시간 0으로 설정
    dp = [[INF for _ in range(goal_cop+1)] for _ in range(goal_alp+1)]
    dp[alp][cop] = 0

    for 현재_알고력 in range(alp, goal_alp+1):
        for 현재_코딩력 in range(cop, goal_cop+1):
            # 한 시간 공부하는 경우
            if 현재_알고력 < goal_alp:
                dp[현재_알고력+1][현재_코딩력] = min(dp[현재_알고력+1][현재_코딩력], dp[현재_알고력][현재_코딩력] + 1)
            if 현재_코딩력 < goal_cop:
                dp[현재_알고력][현재_코딩력+1] = min(dp[현재_알고력][현재_코딩력+1], dp[현재_알고력][현재_코딩력] + 1)
            # 풀수 있는 문제 푸는 경우
            for p in problems:
                if p[0] <= 현재_알고력 and p[1] <= 현재_코딩력:
                    보상_알고력 = p[2]
                    보상_코딩력 = p[3]
                    공부시간 = p[4]
                    예상_알고력 = 현재_알고력 + 보상_알고력
                    예상_코딩력 = 현재_코딩력 + 보상_코딩력
                    if goal_alp < 예상_알고력:
                        예상_알고력 = goal_alp
                    if goal_cop < 예상_코딩력:
                        예상_코딩력 = goal_cop
                    dp[예상_알고력][예상_코딩력] = min(dp[예상_알고력][예상_코딩력], dp[현재_알고력][현재_코딩력] + 공부시간)

    return dp[goal_alp][goal_cop]