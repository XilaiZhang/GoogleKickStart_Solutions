
from collections import defaultdict
import heapq
T=int(raw_input())

for tt in range(1,T+1):
    inputString = raw_input()
    validString = raw_input()
    validSet = set([ord(char) for char in validString])
    #print validSet
    result = 0
    for char in inputString:
        temp = ord(char)
        countForward = 0
        while temp not in validSet:
            temp += 1
            countForward += 1
            if temp > ord('z'):
                temp = ord('a')
        
        temp = ord(char)
        countBackward = 0
        while temp not in validSet:
            temp -= 1
            countBackward += 1
            if temp < ord('a'):
                temp = ord('z')

        result += min(countForward, countBackward)
    
    print "Case #"+str(tt)+": "+str(result)

   

