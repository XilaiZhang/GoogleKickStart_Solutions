
from collections import defaultdict
import heapq
T=int(input())

for tt in range(1,T+1):
    I = input()
    P = input()
    p1=0
    p2=0
    r = "IMPOSSIBLE"
    count = 0
    while p1 < len(I) and p2< len(P):
        #print 'p2 is '+str(p2)+" p1 is "+str(p1)

        if P[p2] != I[p1]:
            count+=1
            p2+=1
        else:
            p1+=1
            p2+=1
    if p1 == len(I) and p2 == len(P):
        r = count
    if p2== len(P) and p1<len(I):
        pass
    if p1 == len(I) and p2<len(P):
        count+= len(P)-p2
        r = count

    res = "Case #"+str(tt)+": "+str(r)

    print(res)

   

