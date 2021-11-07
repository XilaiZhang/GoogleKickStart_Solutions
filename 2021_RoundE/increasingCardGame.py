
import math
T=int(raw_input())

bound = int(1e6)

prefixSum = 0
res = [0 for x in range(bound+1)]
for i in range(1, bound+1):
    prefixSum += res[i-1]
    res[i] = prefixSum * 1.0 / i + 1

logConstant = res[bound] - math.log(bound + 1)

for tt in range(1,T+1):
    N = int(raw_input())
    if N <= bound:
        print "Case #"+str(tt)+": "+str(res[N])
    else:
        approximate = math.log(N+1) + logConstant
        print "Case #"+str(tt)+": "+str(approximate)

   

