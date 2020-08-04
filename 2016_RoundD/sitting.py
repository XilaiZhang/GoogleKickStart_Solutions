
T=int(raw_input())

for tt in range(1,T+1):
    R,C=[int(t) for t in raw_input().split()]
    result=None
    if R%3==0:
        result=R*C/3*2
    elif R%3==1:
        result=R*C/3*2+R*C%3
    else:
        if C%3==1 or C%3==0:
            result=R*C/3*2+R*C%3
        elif C%3==2:
            if R==2 or C==2:
                result=R*C/3*2+2
            else:
                result=R*C/3*2+1
    
    print "Case #"+str(tt)+": "+str(result)