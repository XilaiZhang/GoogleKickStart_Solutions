
T=int(raw_input())

for tt in range(1,T+1):
    K=int(raw_input())
    A=[int(t) for t in raw_input().split()]
    result=10000
    dp=[[10001 for y in range(4)] for x in range(K)]
    dp[0][0]=0
    dp[0][1]=0
    dp[0][2]=0
    dp[0][3]=0
    for i in range(1,K):
        for j in range(4):
            for k in range(4):
                if A[i]>A[i-1]:
                    if j>k:
                        dp[i][j]=min(dp[i][j], dp[i-1][k])
                    elif j<=k:
                        dp[i][j]=min(dp[i][j], dp[i-1][k]+1) 
                elif A[i]<A[i-1]:
                    if j<k:
                        dp[i][j]=min(dp[i][j], dp[i-1][k])
                    elif j>=k:
                        dp[i][j]=min(dp[i][j], dp[i-1][k]+1) 
                else:
                    if j==k:
                        dp[i][j]=min(dp[i][j],dp[i-1][k])
                    else:
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+1)
    print "Case #"+str(tt)+": "+str(min(dp[K-1][0],dp[K-1][1],dp[K-1][2],dp[K-1][3]))
    




    
