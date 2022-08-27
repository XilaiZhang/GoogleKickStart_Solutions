from bisect import bisect
T=int(input())
import math

for tt in range(1,T+1):
    N = int(input())
    
    print("Case #"+str(tt)+": "+str(max(1, math.ceil(N/5))))
    

