n = int(input())
arr = list(map(int, input().split()))
arr = arr[::-1]

dp = [1] * n

# 현재 나를 기준으로
for i in range(1, n):
    # 내 앞에 녀석들 중에
    for j in range(0, i):
        # 나보다 작은 녀석이면 내 앞에 포함되어도 되는거니까,
        if arr[j] < arr[i]:
            # 지금 그 녀석을 포함하지 않는 경우에 나까지의 최장길이
            # vs
            # 그 작은 녀석을 포함시키면서 최장길이
            dp[i] = max(dp[i], dp[j] + 1)

# 뭐가 빠지고 포함됐던 최장길이는 dp의 어딘가에 있다. 반드시 끝이라고 보장 X
print(n - max(dp))