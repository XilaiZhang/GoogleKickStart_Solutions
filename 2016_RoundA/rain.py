import heapq
T=int(raw_input())

for tt in range(1,T+1):
    R,C=[int(t) for t in raw_input().split()]
    grid=[]
    for i in range(R):
        grid.append([int(t) for t in raw_input().split()])
        
    seen=set()
    h=[]
    
    for j in range(1,C-1):
        heapq.heappush(h,[grid[0][j],0,j]) 
        heapq.heappush(h,[grid[R-1][j],R-1,j]) 
        seen.add((0,j))
        seen.add((R-1,j))
        
    for i in range(1,R-1):
        heapq.heappush(h,[grid[i][0],i,0]) 
        heapq.heappush(h,[grid[i][C-1],i,C-1]) 
        seen.add((i,0))
        seen.add((i,C-1))

    seen.add((0,0))
    seen.add((R-1,0))
    seen.add((0,C-1))
    seen.add((R-1,C-1))
    
    result=0    
    while h:
        height,x,y=heapq.heappop(h)
        

        tx=[-1,0,1,0]
        ty=[0,1,0,-1]
        for n in range(4):
            newX=x+tx[n]
            newY=y+ty[n]
            if (newX,newY) in seen or newX<0 or newX>=R or newY<0 or newY>=C:
                continue
            if grid[newX][newY]<height:
                result+=height-grid[newX][newY]
                heapq.heappush(h,[height,newX,newY])
            else:
                heapq.heappush(h,[grid[newX][newY],newX,newY])
            seen.add((newX,newY))
            
    print "Case #"+str(tt)+": "+str(result)
                