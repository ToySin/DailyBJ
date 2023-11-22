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