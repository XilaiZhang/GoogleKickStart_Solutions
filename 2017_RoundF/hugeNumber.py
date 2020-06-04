from collections import defaultdict
T=raw_input()
T=int(T)

fact=1
factDict=defaultdict(lambda:10**5+1)
j=1
while True:
    fact*=j
    if fact>10**5:
        break
    factDict[j]=fact
    j+=1

for m in range(1,T+1):
    A,N,P=raw_input().split()
    A,N,P=int(A),int(N),int(P)
    remainderDict=defaultdict()
    bound=factDict[N]

    currentVal=A%P
    seq=1
    
    while currentVal not in remainderDict:
        remainderDict[currentVal]=seq
        seq+=1
        bound-=1
        if bound==0:
            break
        currentVal=(currentVal*A)%P

    result=1
    if bound==0:
        result=currentVal
    else:
        offset=remainderDict[currentVal]-1
        period=seq-remainderDict[currentVal]
        small=1
        for t in range(1,N+1):
            small=(small*t)%period #small could be 0 in this case
        
        small=small+(period-offset)%period
        #handle the case of small==0
        if small==0:
            small=period
        for t in range(small-1):
            currentVal=(currentVal*A)%P
        result=currentVal
    print "Case #"+str(m)+": "+str(result)

    
        

