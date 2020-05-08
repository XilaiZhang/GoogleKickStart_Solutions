T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N=raw_input()
    N=int(N)
    interval=(N+1)/2
    numbers=[int(t) for t in raw_input()]
    l=0
    r=l+interval-1
    currentSum=sum(numbers[:r+1])
    result=currentSum
    while r<N-1:
        currentSum-=numbers[l]
        l+=1
        currentSum+=numbers[r+1]
        r+=1
        result=max(result,currentSum)
    print "Case #"+str(tt)+": "+str(result)
        
        

