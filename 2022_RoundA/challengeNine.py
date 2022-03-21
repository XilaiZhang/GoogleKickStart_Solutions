
from collections import defaultdict
import heapq
T=int(input())

for tt in range(1,T+1):
    numberString = input()
    number = [int(x) for x in numberString]
    tsum = sum(number)
    adder = 9 - (tsum % 9)
    if adder == 9:
        adder = 0

    if adder == 0:
        l = len(number)
        res = ''
        for i in range(1,l):
            if adder < number[i]:
                res = numberString[:i] + str(adder) + numberString[i:]
                break
        if res == '':
            res = numberString + str(adder)
        res = "Case #"+str(tt)+": "+res
        print(res)
        continue

    l = len(number)
    res = ''
    for i in range(l):
        if adder < number[i]:
            res = numberString[:i] + str(adder) + numberString[i:]
            break
    #print('i is '+str(i))
    if res == '':
        res = numberString + str(adder)
    res = "Case #"+str(tt)+": "+res

    print(res)

   

