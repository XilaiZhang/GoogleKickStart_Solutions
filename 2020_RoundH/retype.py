from collections import defaultdict
T=int(raw_input())

for tt in range(1,T+1):
    N,K,S=[int(t) for t in raw_input().split()]
    result=K-1
    result+=min(1+N, K-S+N-S+1)
    
    print "Case #"+str(tt)+": "+str(result)
        

