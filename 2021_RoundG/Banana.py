from collections import defaultdict
import sys
T=int(raw_input())

for tt in range(1,T+1):
    N, K = [int(x) for x in raw_input().split()]
    B = [int(y) for y in raw_input().split()]
    minLengthForSum = [sys.maxint for y in range(K+1)]
    minLengthForSum[0] = 0
    ans = sys.maxint
    for i in range(N):
        secondSum = 0
        for j in range(i, N):
            secondSum += B[j]
            if secondSum > K:
                break
            if minLengthForSum[K - secondSum]!= -1:
                ans = min(ans, minLengthForSum[K-secondSum] + j-i+1)

        firstSum = 0
        for j in range(i,-1,-1):
            firstSum += B[j]
            if firstSum > K:
                break
            if minLengthForSum[firstSum] == -1:
                minLengthForSum[firstSum] = i-j+1
            else:
                minLengthForSum[firstSum] = min(minLengthForSum[firstSum], i-j+1)
    if ans == sys.maxint:
        ans = -1

    print "Case #"+str(tt)+": "+str(ans)
