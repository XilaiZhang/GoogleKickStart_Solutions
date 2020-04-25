import fileinput
from collections import defaultdict

seq=1
caseNum=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

while seq<len(lines):
    N,H=lines[seq].split()
    N=int(N)
    H=int(H)
    dp=[0 for x in range(1<<N)]

    A=[int(t) for t in lines[seq+1].split()]
    B=[int(t) for t in lines[seq+2].split()]
    
    for aState in range(1<<N):
        count=0
        for i in range(N):
            if (aState & (1<<i)):
                count+=A[i]
        if count>=H:
            dp[aState]=1
    #print dp
    for i in range(N):
        for state in range((1<<N)-1,-1,-1):
            if (state & (1<<i)):
                dp[state ^ (1<<i)]+=dp[state]
    #print dp
    result=0
    for bState in range(1<<N):
        count=0
        Amask=0
        for i in range(N):
            if (bState & (1<<i)):
                count+=B[i]
            else:
                Amask|=(1<<i)
        if count<H:
            continue
        else:
            result+=dp[Amask]
    print "Case #"+str(caseNum)+": "+str(result)
    seq+=3
    caseNum+=1
    