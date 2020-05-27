from collections import defaultdict,deque
import sys

T=raw_input()
T=int(T)

def findCycle(point,parent,seen,stack,cycle,neighbor):
    if point in seen:
        while stack[-1]!=point:
            cycle.append(stack[-1])
            stack.pop()
        cycle.append(point)
        return True
    else: 
        seen.add(point)
        for n in neighbor[point]:
            if n==parent:
                continue
            stack.append(point)
            if findCycle(n,point,seen,stack,cycle,neighbor):
                return True
            else:
                stack.pop()

for t in range(1,T+1):
    result=""
    N=raw_input()
    N=int(N)
    neighbor=defaultdict(list)
    for i in range(N):
        a,b=raw_input().split()
        a,b=int(a),int(b)
        neighbor[a].append(b)
        neighbor[b].append(a)
    cycle=[]
    seen=set()
    stack=[]

    findCycle(1,-1,seen,stack,cycle,neighbor)

    raw=[0 for i in range(N+1)]
    past=set()
    q=deque()
    for k in cycle:
        q.append([k,0])
    while q:
        node,dist=q.popleft()
        if node in past:
            continue
        past.add(node)
        raw[node]=dist
        for n in neighbor[node]:
            q.append([n,dist+1])
    for i in range(1,N+1):
        result+=" "+str(raw[i])

    print "Case #"+str(t)+":"+result

    
        

