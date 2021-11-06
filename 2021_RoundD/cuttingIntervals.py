T = int(raw_input())
from collections import Counter
import heapq
for tt in range(1,T+1):
    N,C = [int(t) for t in raw_input().split()]

    x = Counter()
    for i in range(N):
        a,b = [int(t) for t in raw_input().split()]
        x[a+1] += 1
        x[b] -=1

    #print x
    l2 = []
    for start in x:
        quantity = x[start]
        l2.append([start, quantity])
    l2.sort()
    #print l2
    base = 0
    for i in range(len(l2)):
        base += l2[i][1]
        l2[i][1] = base
    #print l2

    l3 = []
    for i in range(1, len(l2)):
        interval = l2[i][0]-l2[i-1][0]
        value = l2[i-1][1]
        if interval > 0 and value>0:
            l3.append([-value, interval])

    l3.sort()
    #print l3

    r = 0
    idx = 0
    while idx<len(l3) and C>0:
        cut, many = l3[idx]
        cut = -cut
        if many<=C:
            C-=many
            r += many*cut
        else:
            r += C*cut
            break
        idx+=1
    

    print "Case #"+str(tt)+": "+str(r+N)
