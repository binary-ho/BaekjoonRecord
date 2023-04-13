import sys
input = lambda : sys.stdin.readline().rstrip()
k = 1
while True :
    n = int(input())
    if n == 0 :
        break
    jido = [list(map(int, input().split())) for _ in range(n)]
    dp = [[0,0, 0] for _ in range(n)]
    dp[0][0] = 1000001
    dp[0][1] = jido[0][1]
    dp[0][2] = dp[0][1] + jido[0][2]
    dp[1][0] = jido[0][1] + jido[1][0]
    dp[1][1] = min(dp[1][0], dp[0][1], dp[0][2]) + jido[1][1]
    dp[1][2] = min(dp[1][1], dp[0][1], dp[0][2]) + jido[1][2]
    for i in range(2, n) :
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + jido[i][0]
        dp[i][1] = min(dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]) + jido[i][1]
        dp[i][2] = min(dp[i-1][1], dp[i-1][2], dp[i][1]) + jido[i][2]
    print('%d.'%(k), dp[n-1][1])
    k += 1