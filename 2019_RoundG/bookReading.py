import fileinput
from collections import defaultdict

seq=1
caseNum=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

while seq<len(lines):
    N,M,Q=lines[seq].split()
    N=int(N)
    torns=set([int(t) for t in lines[seq+1].split()])
    
    factors=[int(f) for f in lines[seq+2].split()]

    lookup=[0]
    for i in range(1,N+1):
        it=i
        count=0
        while it<=N:
            if it not in torns:
                count+=1
            it+=i
        lookup.append(count)

    
    
    #print torns
    result=0
    for f in factors:
        result+=lookup[f]
    

    print "Case #"+str(caseNum)+": "+str(result)
    seq+=3
    caseNum+=1
    