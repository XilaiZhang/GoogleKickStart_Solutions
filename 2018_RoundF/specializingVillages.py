from collections import defaultdict
T=raw_input()
T=int(T)
mod=10**5+1
for tt in range(1,T+1):
    V,E=raw_input().split()
    V,E=int(V),int(E)
    minDist=[mod for i in range(V+1)]
    minNeighbor=[0 for i in range(V+1)]
    spa,spb=0,0
    for i in range(E):
        a,b,dist=raw_input().split()
        a,b,dist=int(a),int(b),int(dist)
        if dist==0:
            spa=a
            spb=b
        if dist<minDist[a]:
            minDist[a]=dist
            minNeighbor[a]=b
        if dist<minDist[b]:
            minDist[b]=dist
            minNeighbor[b]=a
    neighbor=defaultdict(set)
    for i in range(1,len(minNeighbor)):
        neighbor[i].add(minNeighbor[i])
        neighbor[minNeighbor[i]].add(i)
    seen=set()
    component=0
    for x in range(1,V+1):
        if x in seen:
            continue
        component+=1
        q=[x]
        while q:
            node=q.pop()
            if node in seen:
                continue
            seen.add(node)
            for n in neighbor[node]:
                q.append(n)
    #print component
    #print neighbor
    if spa:
        component+=len(neighbor[spa])-1
        component+=len(neighbor[spb])-1
    result=2**(component)
    print "Case #"+str(tt)+": "+str(result)

    
        

