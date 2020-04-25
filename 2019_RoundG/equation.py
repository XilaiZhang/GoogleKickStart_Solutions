import fileinput
from collections import defaultdict

seq=1
caseNum=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

while seq<len(lines):
    N,M=lines[seq].split()
    N=long(N)
    M=long(M)
    numbers=[long(t) for t in lines[seq+1].split()]
    numOnes=[0 for x in range(64)]
    candidate=0
    smallest=0
    for i in range(63,-1,-1):
        ref=(1<<i)
        for num in numbers:
            if (num&ref):
                numOnes[63-i]+=1
        if numOnes[63-i]<N-numOnes[63-i]:
            smallest+=(numOnes[63-i]<<i)
        else:
            smallest+=((N-numOnes[63-i])<<i)
    #print numOnes
    #print smallest
    if smallest>M:
        print "Case #"+str(caseNum)+": "+str(-1)
        seq+=2
        caseNum+=1
        continue
    
    candidate=0
    for i in range(63,-1,-1):
        if numOnes[63-i]>=N-numOnes[63-i]:
            candidate=((1<<i)| candidate)
            continue
        else:
            if smallest+((N-numOnes[63-i]-numOnes[63-i])<<i)<=M:
                candidate=((1<<i)| candidate)
                smallest=smallest+((N-numOnes[63-i]-numOnes[63-i])<<i)

    print "Case #"+str(caseNum)+": "+str(candidate)
    seq+=2
    caseNum+=1
    