
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N=raw_input()
    N=int(N)
    A=[]
    B=[]
    total=0
    for i in range(N):
        S,E,L=raw_input().split()
        S,E,L=int(S),int(E),int(L)
        total+=S
        if L==0:
            B.append(E)
        else:
            A.append([S,E,L])
    A.sort(key=lambda x:float(x[0])/x[2])
    C=len(A)
    dp=[[0 for y in range(total+1)] for x in range(C)]
    if C>0:
        dp[0][A[0][0]]=A[0][1]
    for i in range(1,C):
        for j in range(total+1):
            dp[i][j]=max(dp[i][j],dp[i-1][j])
            if j>=A[i][0]:
                penalty=j-A[i][0]
                remainder=A[i][1]-penalty*A[i][2]
                if remainder<=0:
                    continue
                dp[i][j]=max(dp[i][j],dp[i-1][penalty]+remainder)
    result=0
    if C>0:
        for t in range(total+1):
            result=max(result,dp[C-1][t])
    for good in B:
        result+=good
    
    print "Case #"+str(tt)+": "+str(result)


    