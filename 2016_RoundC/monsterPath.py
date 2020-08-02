from collections import Counter
T=int(raw_input())
R,C,P,Q=[None for x in range(4)]

def dfs(grid, x,y, S, seen):
    global R,C,P,Q
    if S==0:
        return 0
    if x<0 or x>=R or y<0 or y>=C:
        return 0

    seen[x,y]+=1
    ans=max(dfs(grid,x+1,y,S-1,seen),dfs(grid,x-1,y,S-1,seen),
        dfs(grid,x,y+1,S-1,seen),dfs(grid,x,y-1,S-1,seen))
    seen[x,y]-=1

    if grid[x][y]=="A":
        ans+=((1-P)**seen[x,y])*P
    else:
        ans+=((1-Q)**seen[x,y])*Q
    
    return ans

for tt in range(1,T+1):
    R,C,RS,CS,S=[int(t) for t in raw_input().split()]
    P,Q=[float(t) for t in raw_input().split()]

    grid=[]
    for i in range(R):
        grid.append(raw_input().split())
    seen=Counter()
    result=max(dfs(grid,RS+1,CS,S,seen),dfs(grid,RS-1,CS,S,seen),
        dfs(grid,RS,CS+1,S,seen),dfs(grid,RS,CS-1,S,seen))

    print "Case #"+str(tt)+": %.7f" %(result)
                