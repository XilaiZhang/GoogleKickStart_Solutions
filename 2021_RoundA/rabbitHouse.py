import heapq
T=int(raw_input())

for tt in range(1,T+1):
    R,C = [int(t) for t in raw_input().split()]
    grid = [[0 for y in range(C)] for x in range(R)]
    result = 0
    q=[]
    seen = [[False for y in range(C)] for x in range(R)]
    minVal = [[0 for y in range(C)] for x in range(R)]
    for i in range(R):
        line = [int(t) for t in raw_input().split()]
        for j in range(len(line)):
            heapq.heappush(q, [-line[j], i, j])
            minVal[i][j]=line[j]
            grid[i][j]=line[j]
    while q:
        val, i, j = heapq.heappop(q)
        val = -val
        if seen[i][j]:
            continue
        
        if val < minVal[i][j]:
            continue
        seen[i][j]=True
        result+= val-grid[i][j]
        if i and (val-1)>minVal[i-1][j]:
            minVal[i-1][j]=val-1
            heapq.heappush(q, [-val+1, i-1, j])
        if i<R-1 and (val-1)>minVal[i+1][j]:
            minVal[i+1][j]=val-1
            heapq.heappush(q, [-val+1, i+1, j])   
        if j and (val-1)>minVal[i][j-1]:
            minVal[i][j-1]=val-1
            heapq.heappush(q, [-val+1, i, j-1])
        if j<C-1 and (val-1)>minVal[i][j+1]:
            minVal[i][j+1]=val-1
            heapq.heappush(q, [-val+1, i, j+1])   
    
    
    print "Case #"+str(tt)+": "+str(result)





    







        

