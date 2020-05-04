from collections import Counter
import copy
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N,Q=raw_input().split()
    N,Q=int(N),int(Q)
    word=raw_input()
    
    prefix=[Counter()]
    for c in word:
        myDict=copy.deepcopy(prefix[-1])
        myDict[c]+=1
        prefix.append(myDict)
    #print prefix
    result=0
    for i in range(Q):
        start,end=raw_input().split()
        
        start=int(start)-1
        end=int(end)
        remainder=Counter()
        badCount=0
        for key in prefix[end]:
            count=prefix[end][key]-prefix[start][key]
            if count>0 and count%2==1:
                badCount+=1
        #print str(start)+" "+str(end)+" "+str(badCount)
        if badCount<2:
            result+=1
  
   
    print "Case #"+str(tt)+": "+str(result)


    