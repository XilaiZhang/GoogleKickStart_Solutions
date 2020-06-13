from collections import Counter
T=raw_input()
T=int(T)

F1=["T" for x in range(50)]
F2=["T" for x in range(50)]
for tt in range(1,T+1):
    N,Q=[int(t) for t in raw_input().split()]
    line=raw_input()
    for i in range(Q):
        F1[i]=line[i]
    if N>1:
        line=raw_input()
        for i in range(Q):
            F2[i]=line[i]

    my=raw_input()
    One=0
    Two=0
    Three=0
    Four=0
    for i in range(Q):
        if my[i]==F1[i]:
            if my[i]==F2[i]:
                One+=1
            else:
                Two+=1
        else:
            if my[i]==F2[i]:
                Three+=1
            else:
                Four+=1
    
    s1=0
    s2=0
    score=[int(t) for t in raw_input().split()]
    if N>1:
        s1,s2=score
    else:
        s1=score[0]

    result=0
    for a in range(One+1):
        for b in range(Two+1):
            for c in range(Three+1):
                for d in range(Four+1):
                    p1=a+b+Three-c+Four-d
                    if p1!=s1:
                        continue
                    if N>1:
                        p2=a+Two-b+c+Four-d
                        if p2!=s2:
                            continue
                    result=max(result,a+b+c+d)

    print "Case #"+str(tt)+": "+str(result)

    
        

