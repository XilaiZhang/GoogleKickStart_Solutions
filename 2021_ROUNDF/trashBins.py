import sys
T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    bins = raw_input()
    dp = [0 for x in range(N)]
    prev = -1
    for i in range(N):
        if bins[i] == "1":
            prev = i
            continue
        else:
            if prev < 0:
                dp[i] = sys.maxint
            else:
                dp[i] = i - prev
    #print dp

    prev = -1
    result = 0
    for j in range(N-1,-1,-1):
        if bins[j] == "1":
            prev = j
            continue
        else:
            if prev < 0:
                result += dp[j]
                continue
            else:
                #print "at pos "+str(j)+" "+str(min(dp[j], prev-j))
                result += min(dp[j], prev-j)



    
    print "Case #"+str(tt)+": "+str(result)

   

