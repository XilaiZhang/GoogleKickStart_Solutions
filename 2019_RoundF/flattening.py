import fileinput
import sys
from collections import Counter

seq=1
caseNum=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

result=0

while seq<len(lines):
    N,K=lines[seq].split()
    N=int(N)
    K=int(K)
    dp=[[0 for j in range(N)] for i in range(N)]
    numbers=[int(t) for t in lines[seq+1].split()]
    for i in range(N):
        lookup=Counter()
        count=0
        maxCount=0
        for j in range(i,N):
            lookup[numbers[j]]+=1
            count+=1
            if lookup[numbers[j]]>maxCount:
                maxCount=lookup[numbers[j]]
            dp[i][j]=count-maxCount
    #print dp
    M=[[sys.maxint for j in range(K+1)]for i in range(N)]
    for s in range(K):
        M[0][s]=0
    for i in range(1,N):
        M[i][0]=dp[0][i]
        for j in range(1,K+1):
            for t in range(i):
                M[i][j]=min(M[i][j],M[t][j-1]+dp[t+1][i])
    #print M
    print "Case #"+str(caseNum)+": "+str(M[N-1][K])
    seq+=2
    caseNum+=1
    