# 최종 목적은 가장 긴 증가 부분 수열의 길이 구하기
# LIS로 풀기
# 현재 위치에서
# 내 앞의 숫자 들 중 나보다 작은거면 (나보다 크면 내가 못낀다)
# 그녀석까지의 최대값 + 1(내가 들어감) vs 지금 현재 나의 최대 길이

n = int(input())
arr = list(map(int, input().split()))

dp = [1] * n

for i in range(1, n):
    for j in range(i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[j] + 1, dp[i])

print(max(dp))
