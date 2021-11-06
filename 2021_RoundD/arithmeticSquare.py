T = int(raw_input())
from collections import Counter
for tt in range(1,T+1):
    l1 = [int(t) for t in raw_input().split()]
    l2 = [int(t) for t in raw_input().split()]
    l3 = [int(t) for t in raw_input().split()]
    c = Counter()

    numbers = [(l1[0]+l3[2]), (l1[2]+l3[0]), (l2[0]+l2[1]), l1[1]+l3[1]]
    for num in numbers:
        if num%2==0:
            c[num/2]+=1
    r = 0
    for key in c:
        if c[key]>r:
            r=c[key]
    
    base = 0
    if l1[1]*2 == l1[0]+l1[2]:
        base+=1
    if l3[1]*2 == l3[0]+l3[2]:
        base+=1
    if l2[0]*2 == l1[0]+l3[0]:
        base+=1
    if l2[1]*2 == l1[2]+l3[2]:
        base+=1

    print "Case #"+str(tt)+": "+str(base+r)
