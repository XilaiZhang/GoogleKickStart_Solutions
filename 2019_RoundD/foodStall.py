import heapq
import sys
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    K,N=raw_input().split()
    K,N=int(K),int(N)
    pos=raw_input().split()
    pos=[[int(t)] for t in pos]
    cost=raw_input().split()
    for x in range(len(cost)):
        pos[x].append(int(cost[x]))
    pos.sort(key=lambda x:x[0])

    minCost=sys.maxint 
    halfK=K/2
    otherHalf=K-halfK
    cumLeft=[-1 for x in range(len(pos))]
    cumRight=[-1 for x in range(len(pos)+1)]
    h1=[]
    sumLeft=0
    i=0
    while len(h1)<halfK:
        pay=pos[-1][0]-pos[i][0]+pos[i][1]
        heapq.heappush(h1,-pay)
        sumLeft+=pay
        i+=1
    cumLeft[halfK]=sumLeft-halfK*(pos[-1][0]-pos[halfK][0])
    for i in range(halfK,N-1):
        newPay=pos[-1][0]-pos[i][0]+pos[i][1]
        heapq.heappush(h1,-newPay)
        old=heapq.heappop(h1)
        sumLeft=sumLeft+newPay-(-old)
        cumLeft[i+1]=sumLeft-halfK*(pos[-1][0]-pos[i+1][0])
    #print cumLeft
    h2=[]
    j=N-1
    sumRight=0
    while len(h2)<otherHalf:
        pay=pos[j][0]-pos[0][0]+pos[j][1]
        heapq.heappush(h2,-pay)
        sumRight+=pay
        j-=1
    cumRight[N-otherHalf-1]=sumRight-otherHalf*(pos[N-otherHalf-1][0]-pos[0][0])
    result=cumRight[N-otherHalf-1]+cumLeft[N-otherHalf-1]+pos[N-otherHalf-1][1]
    for j in range(N-otherHalf-1,0,-1):
        if cumLeft[j-1]==-1:
            break
        newPay=pos[j][0]-pos[0][0]+pos[j][1]
        heapq.heappush(h2,-newPay)
        old=heapq.heappop(h2)
        sumRight=sumRight+newPay-(-old)
        cumRight[j-1]=sumRight-otherHalf*(pos[j-1][0]-pos[0][0])
        result=min(result, cumRight[j-1]+cumLeft[j-1]+pos[j-1][1])
         

    print "Case #"+str(tt)+": "+str(result)


    