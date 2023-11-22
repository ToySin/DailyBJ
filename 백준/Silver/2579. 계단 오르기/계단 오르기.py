# 최종 목표는 마지막 도착 계단에 최고 점수와 함께 도달하는 것
# 매 계단에 최고 점수로 도달하는 법을 찾자

# 계단은 한 계단 or 두 계단 씩 오를 수 있음
# 연속으로 세개의 계단을 밟을 순 없음
# 일단 내 계단까지 오는걸 생각해보면
# 두칸 전에서 올라오냐? 한칸 전에서 올라오냐? 로 나뉜다.
# 밑에서 잘 했겠거니와.. 하면서 이번칸에서 두 방법중 최댓값을 구한다.

# 최저 계단에 도착했다 -> step == 0
# def dfs(step, cnt):
#     # 시작점
#     if step < 0:
#         return 0
#     # 최저 계단
#     if step == 0:
#         dp[step] = arr[step]
#     # 이미 결과를 아는 경우
#     if dp[step] != 0:
#         return dp[step]

#     # 연속으로 1개째 밟고 있는 경우
#     if cnt == 1:
#         dp[step] = arr[step] + max(dfs(step-1, cnt+1), dfs(step-2, 1))
#     # 연속으로 2개째 밝고 있는 경우 무조건 두칸
#     else:
#         dp[step] = arr[step] + dfs(step-2, 1)
#     return dp[step]


N = int(input())
arr = [int(input()) for _ in range(N)]

dp = [0] * N
dp[0] = arr[0]
if N > 1:
    dp[1] = arr[0] + arr[1]
if N > 2:
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2])

# 나한테 도작하는걸 생각해보면
# 두칸을 넘어서 오느냐
# 한칸 전에서 오느냐 차이다.
# 올바르게 왔다고 가정하면
# 한칸전에서 온 경우: 세칸전 최대 + 전칸 + 이번칸
# 두칸전에서 온 경우: 두칸전 최대 + 이번칸
for i in range(3, N):
    # 두칸 전 + 이번 or 한칸 전에서 와서 건너뛰기
    dp[i] = max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i])

print(dp[-1])

# 올바르게 올라오게 만들지 말고
# 올바르게 올라온 상황이 어떤 상황인지 생각하기