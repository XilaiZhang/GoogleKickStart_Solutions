from random import randint
import math
T=int(input())

    
for tt in range(1,T+1):
    R, A, B = [int(x) for x in input().split()]
    area = 0
    r = R
    res = 0
    count = 0
    while r>0:
        res += math.pi * r**2
        if count % 2==0:
            r *= A 
        else:
            r = int(r/B)
        count+=1

    print('Case #'+str(tt)+": "+str(res))



   

