import sys
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N,P=raw_input().split()
    N,P=int(N),int(P)
    numbers=[int(t) for t in raw_input().split()]
    numbers.sort()
    result=sys.maxint
    prefix=[0]
    currentSum=0
    for num in numbers:
        currentSum+=num
        prefix.append(currentSum)
    for left in range(1,N-P+2):
        result=min(result,numbers[left+P-1-1]*P-(prefix[left+P-1]-prefix[left-1]))

    print "Case #"+str(tt)+": "+str(result)
        

