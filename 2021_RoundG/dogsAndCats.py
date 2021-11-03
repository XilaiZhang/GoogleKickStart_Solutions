import sys, heapq
from collections import defaultdict
T=int(raw_input())

for tt in range(1,T+1):
    N,D,C,M = [int(x) for x in raw_input().split()]
    S = raw_input()
    i = 0
    while i<len(S):
        if S[i] == 'C':
            if C==0:
                break
            else:
                C-=1
        else:
            if D==0:
                break
            else:
                D-=1
                C+=M
        i += 1
    #print "i is "+str(i)
    good = True
    for j in range(i, len(S)):
        if S[j] == 'D':
            good = False
            break

    if good:
        print "Case #"+str(tt)+": "+"YES"
    else:
        print "Case #"+str(tt)+": "+"NO"