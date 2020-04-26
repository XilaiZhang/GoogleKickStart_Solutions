import fileinput
from collections import Counter

seq=1
caseNum=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

result=0

while seq<len(lines):
    N,S=lines[seq].split()
    N=int(N)
    S=int(S)
    dp=Counter()
    result=0
    for i in range(seq+1,seq+N+1):
        lines[i]=[int(t) for t in lines[i].split()[1:]]
        lines[i].sort()
        dp[tuple(lines[i])]+=1
    #print dp
    for i in range(seq+1,seq+N+1):
        j=len(lines[i])
        children=0
        for state in range(1<<j):
            sub=[]
            for t in range(j):
                if ((1<<t)&state):
                    sub.append(lines[i][t])
            sub.sort()
            children+=dp[tuple(sub)]
        result+=N-children


    print "Case #"+str(caseNum)+": "+str(result)
    seq+=N+1
    caseNum+=1
    