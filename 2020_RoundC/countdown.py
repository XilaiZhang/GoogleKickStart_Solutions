
T=raw_input()
T=int(T)
        
for tt in range(1,T+1):
    N,K=raw_input().split()
    N,K=int(N),int(K)
    result=0
    numbers=[int(t) for t in raw_input().split()]
    target=K
    for i in range(len(numbers)):
        if numbers[i]==target:
            target-=1
            if target==0:
                result+=1
                target=K
        else:
            target=K
            if numbers[i]==target:
                target-=1
    print "Case #"+str(tt)+": "+str(result)

    
        

