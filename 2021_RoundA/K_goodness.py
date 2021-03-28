T=int(raw_input())

for tt in range(1,T+1):
    N,K = [int(t) for t in raw_input().split()]
    S = raw_input()
    base=0
    for i in range(N/2):
        if S[i]!=S[N-i-1]:
            base+=1

    
    print "Case #"+str(tt)+": "+str(abs(K-base))





    







        

