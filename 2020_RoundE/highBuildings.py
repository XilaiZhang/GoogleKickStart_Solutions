from collections import deque
T=int(raw_input())

for tt in range(1,T+1):
    N,A,B,C=[int(t) for t in raw_input().split()]
    if N==1:
        print "Case #"+str(tt)+": 1"
        continue

    result=deque([N for x in range(C)])
    diff1=A-C
    diff2=B-C
    if diff1+diff2+C>N:
        print "Case #"+str(tt)+": "+"IMPOSSIBLE"
        continue
    
    if N==2:
        if C==2:
            print "Case #"+str(tt)+": 2 2"
            continue
        
        if A==2 and B==1:
            print "Case #"+str(tt)+": 1 2"
            continue
        elif A==1 and B==2:
            print "Case #"+str(tt)+": 2 1"
            continue
        else:
            print "Case #"+str(tt)+": "+"IMPOSSIBLE"
            continue
    if A==C and B==C and C<N:
        if C>=2:
            r=" "+str(N)+" 1"*(N-C)+(" "+str(N))*(C-1)
            print "Case #"+str(tt)+":"+r
            continue
        print "Case #"+str(tt)+": "+"IMPOSSIBLE"
        continue

    if diff2>0:
        for x in range(N-C-diff1-diff2):
            result.append(1)
    for x in range(diff2):
        result.append(2)

    if diff2==0 and diff1>0:
        for x in range(N-C-diff1-diff2):
            result.appendleft(1)
    for x in range(diff1):
        result.appendleft(2)

    r=""
    for y in result:
        r+=" "+str(y)
    print "Case #"+str(tt)+":"+r

