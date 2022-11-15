T=int(input())   

for tt in range(1,T+1):
    L = int(input())
    inf = 100001

    dp = [x for x in range(L+1)]

    for i in range(2, L+1):
        dp[i] = min(dp[i], dp[i-1] + 1)
        for multiplier in range(L+1):
            target = i * multiplier
            if target > L:
                break
            dp[target] = min(dp[target], dp[i] + 4 + 2*(multiplier-1))

    print("Case #"+str(tt)+": "+str(dp[L]))

   

