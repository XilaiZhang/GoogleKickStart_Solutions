
import heapq
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    R,C,K=raw_input().split()
    R,C,K=int(R),int(C),int(K)
    hist=[[0 for y in range(C)] for x in range(R)]
    for i in range(R):
        row=[int(t) for t in raw_input().split()]
        left=0
        right=1
        minH=[[row[0],0]]
        maxH=[[-row[0],0]]
        invalid=set()
        while right<len(row):
            heapq.heappush(minH,[row[right],right])
            heapq.heappush(maxH,[-row[right],right])
            
            while left<right and (-minH[0][0]-maxH[0][0])>K:
                hist[i][left]=right-1-left+1
                old=row[left]
                invalid.add(left)
                while maxH[0][1] in invalid:
                    heapq.heappop(maxH)
                while minH[0][1] in invalid:
                    heapq.heappop(minH)
                left+=1
            
            right+=1
        for t in range(left,len(row)):
            hist[i][t]=len(row)-1-t+1

    #print hist
    area=0
    for j in range(C):
        s=[]
        for i in range(R):
            if not s or hist[i][j]>=hist[s[-1]][j]:
                s.append(i)
            else:
                while s and hist[s[-1]][j]>hist[i][j]:
                    pivot=s.pop()
                    if not s:  #how could i mess up indentation
                        area=max(area,hist[pivot][j]*(i))
                    else:
                        area=max(area,hist[pivot][j]*(i-s[-1]-1))
                s.append(i)
        while s:
            pivot=s.pop()
            if not s:
                area=max(area,hist[pivot][j]*(R))
            else:
                area=max(area,hist[pivot][j]*(R-s[-1]-1))

    
    print "Case #"+str(tt)+": "+str(area)


    