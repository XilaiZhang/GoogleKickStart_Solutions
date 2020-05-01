from collections import Counter
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N,G,M=raw_input().split()
    N,G,M=int(N),int(G),int(M)
    C=[[] for x in range(N+1)]
    A=[[] for x in range(N+1)]
    result=[0 for x in range(G)]
    groupC=Counter()
    groupA=Counter()
    for g in range(G):
        pos,clock=raw_input().split()
        pos=int(pos)
        if clock=="C":
            C[pos].append(g)
        else:
            A[pos].append(g)
    nextC=-1
    for i in range(N,0,-1):
        C[i].append(nextC)
        if len(C[i])>1:
            nextC=i

    nextA=-1
    for i in range(1,N+1):
        A[i].append(nextA)
        if len(A[i])>1:
            nextA=i

    #print C
    #print A

    for p in range(1,N+1):
        closeC=p-M%N
        if closeC<1:
            closeC+=N
        closeA=p+M%N
        if closeA>N:
            closeA-=N
        
        stepC=0
        if len(C[closeC])==1:
            if C[closeC][-1]==-1:
                stepC+=N+1-closeC
                if len(C[1])>1:
                    closeC=1
                else:
                    if C[1][-1]==-1:
                        stepC=M+1
                    else:
                        stepC+=C[1][-1]-1
                        closeC=C[1][-1]
            else:
                stepC+=C[closeC][-1]-closeC
                closeC=C[closeC][-1]

        stepA=0
        if len(A[closeA])==1:
            if A[closeA][-1]==-1:
                stepA+=closeA
                if len(A[N])>1:
                    closeA=N
                else:
                    if A[N][-1]==-1:
                        stepA=M+1
                    else:
                        stepA+=N-A[N][-1]
                        closeA=A[N][-1]
            else:
                stepA+=closeA-A[closeA][-1]
                closeA=A[closeA][-1]

        if stepC<=M and stepC<=stepA:
            groupC[closeC]+=1
        if stepA<=M and stepA<=stepC:
            groupA[closeA]+=1
        #print str(p)+" "+str(closeC)+" "+str(closeA)+" "+str(stepC)+" "+str(stepA)     
    
    re=""
    for t in groupC:
        C[t].pop()
        for ele in C[t]:
            result[ele]+=groupC[t]
    for t in groupA:
        A[t].pop()
        for ele in A[t]:
            result[ele]+=groupA[t]
    for r in range(len(result)):
        re+=" "+str(result[r])

    print "Case #"+str(tt)+":"+str(re)


    