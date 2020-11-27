from collections import defaultdict
T=int(raw_input())

for tt in range(1,T+1):
    grid=[]
    N=int(raw_input())
    for i in range(N):
        line=[int(t) for t in raw_input().split()]
        grid.append(line)

    result=0
    for diff in range(-N-1, N):
        mySum=0
        sx=max(0,diff)
        sy=sx-diff
        
        while sx>=0 and sx<N and sy>=0 and sy<N:
           mySum += grid[sx][sy] 
           sx=sx+1
           sy=sy+1
        result=max(result,mySum)
    
    print "Case #"+str(tt)+": "+str(result)
        

