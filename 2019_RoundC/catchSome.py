from collections import defaultdict
import sys
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N,K=raw_input().split()
    N,K=int(N),int(K)

    pos=[int(t) for t in raw_input().split()]
    color=defaultdict(list)
    colors=[int(t) for t in raw_input().split()]
    same=[]
    for i in range(len(colors)):
        color[colors[i]].append(pos[i])
    for c in color:
        same.append(sorted(color[c]))
    #print same
    
    C=len(same)   
    dp=[[[sys.maxint for z in range(2)] for j in range(K+1)] for x in range(C)]
    dp[0][0][0]=0
    dp[0][0][1]=0
    for j in range(1,min(len(same[0])+1,K+1)):
        dp[0][j][0]=same[0][j-1]*2
        dp[0][j][1]=same[0][j-1]
    for i in range(1,C):
        for j in range( K+1 ):
            for t in range(min(j+1,len(same[i])+1)):
                if t==0:
                    dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0])
                    dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1])
                else:
                    dp[i][j][0]=min(dp[i][j][0], 2*same[i][t-1]+dp[i-1][j-t][0])
                    dp[i][j][1]=min(dp[i][j][1], 2*same[i][t-1]+dp[i-1][j-t][1])
                    dp[i][j][1]=min(dp[i][j][1], same[i][t-1]+dp[i-1][j-t][0])    
   
    print "Case #"+str(tt)+": "+str(dp[C-1][K][1])


    