from collections import defaultdict,deque
T=raw_input()
T=int(T)

def dfs(grid, x, y,R,C,parent,children):
    q=[[x,y]]
    potential=set()
    while q:
        a,b=q.pop()
        #print "popped is "+str(a)+" "+str(b)
        if a<0 or a>=R or b<0 or b>=C or grid[a][b]!=grid[x][y]:
            continue
        if (a,b) in potential:
            continue
        potential.add((a,b))
        if a!=R-1:
            p=grid[a+1][b]
            if p!=grid[x][y]:
                parent.add(p)
                children[p].add(grid[x][y])
        q.append([a-1,b])
        q.append([a,b+1])
        q.append([a,b-1])
        q.append([a+1,b])
        
for tt in range(1,T+1):
    R,C=raw_input().split()
    R,C=int(R),int(C)
    result=""
    grid=[]
    for i in range(R):
        row=raw_input()
        grid.append(row)
    seen=set()
    parent=defaultdict(set)
    children=defaultdict(set)
    for x in range(R):
        for y in range(C):
            if grid[x][y] not in seen:
                seen.add(grid[x][y])
                dfs(grid,x,y,R,C,parent[grid[x][y]],children)

    s=deque()
    for k in parent:
        if len(parent[k])==0:
            s.append(k)

    while s:
        some=s.popleft()
        result+=some
        for n in children[some]:
            parent[n].discard(some)
            if len(parent[n])==0:
                s.append(n)
                del parent[n]
        parent.pop(some,None)

    if len(parent)>0:
        print "Case #"+str(tt)+": "+str(-1)
    else:
        print "Case #"+str(tt)+": "+str(result)

    
        

