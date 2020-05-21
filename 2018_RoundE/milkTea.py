from collections import defaultdict
import sys
T=raw_input()
T=int(T)

class node(object):
    def __init__(self):
        self.children=defaultdict(node)

def compute(dummy,best,depth,ones,N,P):
    
    if len(dummy.children)==0:
        if depth==P:
            return sys.maxint
        return best[depth+1]
    elif len(dummy.children)==2:
        return min(ones[depth+1]+compute(dummy.children["0"],best,depth+1,ones,N,P), 
            N-ones[depth+1]+compute(dummy.children["1"],best,depth+1,ones,N,P))
    elif "1" in dummy.children:
        return min(N-ones[depth+1]+compute(dummy.children["1"],best,depth+1,ones,N,P),
            ones[depth+1]+best[depth+2])
    elif "0" in dummy.children:
        return min(ones[depth+1]+compute(dummy.children["0"],best,depth+1,ones,N,P),
            N-ones[depth+1]+best[depth+2])
        
for tt in range(1,T+1):
    N,M,P=raw_input().split()
    N,M,P=int(N),int(M),int(P)
    best=[0 for j in range(P+2)]
    ones=[0 for j in range(P+1)]
    for i in range(N):
        n=raw_input()
        for c in range(len(n)):
            if n[c]=="1":
                best[c+1]+=1
                ones[c+1]+=1
    for j in range(1,P+1):
        if best[j]>=(N+1)/2:
            best[j]=N-best[j]
    for i in range(P-1,0,-1):
        best[i]=best[i]+best[i+1]
    dummy=node()
    for i in range(M):
        s=raw_input()
        it=dummy
        for c in s:
            it=it.children[c]
    result=compute(dummy,best,0,ones,N,P)
    print "Case #"+str(tt)+": "+str(result)

    
        

