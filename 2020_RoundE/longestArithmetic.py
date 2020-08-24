
T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    numbers=[int(t) for t in raw_input().split()]
    prev=-1
    current=0
    result=0
    for i in range(1,N):
        diff=numbers[i]-numbers[i-1]
        if diff==prev:
            current+=1
        else:
            prev=diff
            current=1
        result=max(result,current)
    print "Case #"+str(tt)+": "+str(result+1)