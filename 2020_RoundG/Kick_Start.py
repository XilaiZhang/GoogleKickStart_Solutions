from collections import defaultdict
T=int(raw_input())

for tt in range(1,T+1):
    S=raw_input()
    l=len(S)
    result=0
    kickNum=[0]
    count=0

    for i in range(l):
        if S[i:i+4]=="KICK":
            count+=1
        if S[i:i+5]=="START":
            result+=kickNum[i]
        
        kickNum.append(count)

    
    print "Case #"+str(tt)+": "+str(result)
        

