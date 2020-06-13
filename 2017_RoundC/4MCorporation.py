import sys
T=raw_input()
T=int(T)

def solve():
    minimum,maximum, mean,median=[int(t) for t in raw_input().split()]
    if minimum>maximum or minimum>mean or minimum>median or maximum<mean or maximum<median:
        return "IMPOSSIBLE"
    if minimum==maximum and mean==median and minimum==mean:
        return "1"
    if median==1.0*(minimum+maximum)/2 and median==mean:
        return "2"

    answer=sys.maxint
    currentMean=1.0*(median+minimum+maximum)/3
    if currentMean==mean:
        answer=min(answer,3)
    elif currentMean<mean and median+maximum>2*mean:
        k=(mean-minimum)/(median+maximum-2*mean)-1
        remainder=(mean-minimum)%(median+maximum-2*mean)
        if remainder==0:
            answer=min(answer,3+2*k)
        else:
            answer=min(answer,5+2*k)  #confusing, rethink later
    elif currentMean>mean and median+minimum<2*mean:
        k=(maximum-mean)/(2*mean-minimum-median)-1
        remainder=(maximum-mean)%(2*mean-minimum-median)
        if remainder==0:
            answer=min(answer, 3+2*k)
        else:
            answer=min(answer,5+2*k)

    currentMean=1.0*(minimum+maximum+2*median)/4
    if currentMean==mean:
        answer=min(answer,4)
    elif currentMean<mean and median+maximum>2*mean:
        k=(2*mean-median-minimum)/(maximum+median-2*mean)-1
        remainder=(2*mean-median-minimum)%(maximum+median-2*mean)
        if remainder==0:
            answer=min(answer,4+2*k)
        else:
            answer=min(answer,6+2*k)
    elif currentMean>mean and median+minimum<2*mean:
        k=(median+maximum-2*mean)/(2*mean-minimum-median)-1
        remainder=(median+maximum-2*mean)%(2*mean-minimum-median)
        if remainder==0:
            answer=min(answer,4+2*k)
        else:
            answer=min(answer, 6+2*k)

    if answer==sys.maxint:
        return "IMPOSSIBLE"
    else:
        return str(answer)


for tt in range(1,T+1):
    result=solve()
    print "Case #"+str(tt)+": "+str(result)

    
        

