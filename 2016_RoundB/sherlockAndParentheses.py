
T=int(raw_input())

for tt in range(1,T+1):
    L,R=[int(t) for t in raw_input().split()]
    pair=min(L,R)
            
    print "Case #"+str(tt)+": "+str((1+pair)*pair/2)
                