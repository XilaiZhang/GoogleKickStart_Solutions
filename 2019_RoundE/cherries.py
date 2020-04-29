import fileinput
from collections import defaultdict

seq=1
caseNum=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

while seq<len(lines):
    N,M=lines[seq].split()
    N,M=int(N),int(M)
    graph=defaultdict(list)
    for i in range(1,M+1):
        a,b=lines[seq+i].split()
        a,b=int(a),int(b)
        graph[a].append(b)
        graph[b].append(a)
    component=0
    seen=set()
    for node in graph:
        if node in seen:
            continue
        component+=1
        q=[node]
        tmp=[]
        while q:
            while q:
                n=q.pop()
                if n in seen:
                    continue
                else:
                    seen.add(n)
                    for nei in graph[n]:
                        tmp.append(nei)
            q=tmp
            tmp=[]
    result=len(seen)-component+(component+N-len(seen)-1)*2

    print "Case #"+str(caseNum)+": "+str(result)
    seq+=M+1
    caseNum+=1
    