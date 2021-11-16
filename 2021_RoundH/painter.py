
from collections import defaultdict
import heapq
T=int(raw_input())

for tt in range(1,T+1):
    N = int(raw_input())
    target = raw_input()
    prev = defaultdict(lambda: -2)
    result = 0
    for idx, char in enumerate(target):
        if char == 'R' or char== 'O' or char == 'P' or char == 'A':
            if prev['R'] != idx - 1:
                result += 1
            prev['R'] = idx
        if char == 'B' or char == 'P' or char == 'G' or char == 'A':
            if prev['B'] != idx - 1:
                result += 1
            prev['B'] = idx
        if char == 'Y' or char == 'O' or char == 'G' or char == 'A':
            if prev['Y'] != idx - 1:
                result += 1
            prev['Y'] = idx 
    
    print "Case #"+str(tt)+": "+str(result)

   

