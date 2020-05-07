from collections import deque
import sys
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    R,C=raw_input().split()
    R,C=int(R),int(C)
    grid=[]
    offices=set()
    for i in range(R):
        row=[int(c) for c in raw_input()]
        for j in range(C):
            if row[j]==1:
                offices.add((i,j))
        grid.append(row)
    q=deque()
    seen=set()
    dist=[[0 for y in range(C)] for x in range(R)]
    for x,y in offices:
        q.append([x,y,0])
    while q:
        x,y,d=q.popleft()
        if x<0 or x>=R or y<0 or y>=C or (x,y) in seen:
            continue
        seen.add((x,y))
        dist[x][y]=d
        q.append([x+1,y,d+1])
        q.append([x-1,y,d+1])
        q.append([x,y+1,d+1])
        q.append([x,y-1,d+1])

    high=R+C
    low=0
    while low<=high:
        mid=low+(high-low)/2
        maxX1Y1Plus=-sys.maxint-1
        minX1Y1Plus=sys.maxint
        maxX1Y1Minus=-sys.maxint-1
        minX1Y1Minus=sys.maxint
        badPoints=False
        for i in range(R):
            for j in range(C):
                if dist[i][j]>mid:
                    badPoints=True
                    maxX1Y1Plus=max(maxX1Y1Plus,i+j)
                    minX1Y1Plus=min(minX1Y1Plus,i+j)
                    maxX1Y1Minus=max(maxX1Y1Minus,i-j)
                    minX1Y1Minus=min(minX1Y1Minus,i-j)
        if not badPoints:
            high=mid-1
            continue
        flag=False
        for x in range(R):
            for y in range(C):
                if (x,y) in offices:
                    continue
                if abs(maxX1Y1Plus-(x+y))<=mid and abs(minX1Y1Plus-(x+y))<=mid and \
                abs(maxX1Y1Minus+y-x)<=mid and abs(minX1Y1Minus+y-x)<=mid:
                    flag=True
                    break
        if flag:
            high=mid-1
        else:
            low=mid+1


    print "Case #"+str(tt)+": "+str(low)
        

