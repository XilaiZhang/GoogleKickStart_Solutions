
T=raw_input()
T=int(T)
        
for tt in range(1,T+1):
    N,K=raw_input().split()
    N,K=int(N),int(K)
    result=0
    y=[-int(t) for t in raw_input().split()]
    y.sort()
    #print y
    days=0
    belly=K
    while y:
        potential=-y.pop()
        if potential<=days:
            continue
        result+=1
        belly-=1
        if belly==0:
            belly=K
            days+=1

    print "Case #"+str(tt)+": "+str(result)

    
        

