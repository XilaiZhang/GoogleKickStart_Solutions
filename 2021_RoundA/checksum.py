
from collections import defaultdict
T=int(raw_input())

for tt in range(1,T+1):
    N = int(raw_input())
    points = []
    for i in range(N):
        line =[int(t) for t in raw_input().split()]
        for j in range(N):
            if line[j]==-1:
                points.append([i,j])

    graph = defaultdict(list)
    cost=[]
    for i in range(N):
        line =[int(t) for t in raw_input().split()]
        cost.append(line)
    R=raw_input()
    C=raw_input()

    total=0
    maxDist = defaultdict(lambda:-1)
    seen = [False for x in range(2*N)]
    vertices = set()
    for point in points:
        a,b= point
        w=cost[a][b]
        b+=N
        total+=w
        graph[a].append([b,w])
        graph[b].append([a,w])
        vertices.add(a)
        vertices.add(b)

    l=len(vertices)
    count=0
    maxForest=0
    while count<l:
        if len(maxDist)==0:
            randomV = vertices.pop()
            count+=1
            seen[randomV]=True
            for v, w in graph[randomV]:
                if not seen[v]:
                    maxDist[v] = w
            continue
        else:
            g=-1
            maxV=None
            for p in maxDist:
                if maxDist[p]>g:
                    maxV = p
                    g = maxDist[p]
            seen[maxV]=True
            count+=1
            maxForest+=g
            for neighbor, w in graph[maxV]:
                if not seen[neighbor]:
                    if w> maxDist[neighbor]:
                        maxDist[neighbor]=w
            del maxDist[maxV]
            vertices.remove(maxV)

    
    print "Case #"+str(tt)+": "+str(total-maxForest)





    







        

