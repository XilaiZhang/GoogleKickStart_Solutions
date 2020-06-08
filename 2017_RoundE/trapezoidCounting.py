from collections import Counter
from bisect import bisect_left
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N=raw_input()
    N=int(N)
    numbers=[int(t) for t in raw_input().split()]
    helpDict=Counter(numbers)
    vals=[]
    for num in helpDict:
        vals.append([num,helpDict[num]])
    vals.sort()
    #print vals
    prefix=[0 for x in range(len(vals)+1)]
    currentSum=0
    for i in range(len(vals)):
        currentSum+=vals[i][1]
        prefix[i+1]=currentSum

    #print prefix
    result=0

    for mid in range(len(vals)):
        if vals[mid][1]<2:
            continue
        midVal=vals[mid][0]
        m=vals[mid][1]

        if m>=3:
            chooseThree=m*(m-1)*(m-2)/6
            small=prefix[mid]
            pos=bisect_left(vals,[3*midVal,-1])
            pos-=1 #guaranteed to be greater than 1
            big=prefix[pos+1]-prefix[mid+1]
            result+=chooseThree*(small+big)

        baseWays=m*(m-1)/2

        left=0
        right=len(vals)-1
        while left<right:
            if left==mid:
                left+=1
                continue
            if right==mid:
                right-=1
                continue
            while left<right and (1.0*(vals[right][0]-vals[left][0])/2) >=midVal:
                left+=1
                if left==mid:
                    left+=1
            if left>=right:
                right-=1
                left=0
                continue
            rangeSum=prefix[right]-prefix[left] #excluding right but includeing left
            if right>mid and left<=mid:
                rangeSum-=m
            result+=baseWays*vals[right][1]*rangeSum
            #print "when mid is "+str(mid)+" and left right are "+str(left)+" "+str(right)
            #print "result is increased by "+str(baseWays*vals[right][1]*rangeSum)
            right-=1
            left=0



    print "Case #"+str(tt)+": "+str(result)

    
        

