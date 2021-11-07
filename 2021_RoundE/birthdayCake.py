
import math
T=int(raw_input())


for tt in range(1,T+1):
    R, C, K = [int(x) for x in raw_input().split()]
    r1, c1, r2, c2 = [int(x) for x in raw_input().split()]
    m = r2 - r1 + 1
    n = c2 - c1 + 1
    base = 0
    
    minR = min(r1-1, R- r2)
    minC = min(c1-1, C- c2)
    minBoundR = (minR + m - 1) /K +1 + ( m - 1 ) /K +1 + 2 * ((n - 1)/K + 1)
    minBoundC = (minC + n - 1) /K +1 + ( n - 1) /K +1 + 2 * ((m -1)/K + 1)
    base = min(minBoundC, minBoundR)

    if r1 == 1 or r2 == R or c1 == 1 or c2 == C:
        base = 0
        if r1 != 1:
            base += (n-1)/K + 1
        if r2 != R:
            base += (n-1)/K + 1
        if c1 != 1:
            base += (m-1)/K + 1
        if c2 != C:
            base += (m-1)/K + 1

    if K>= n or K>= m:
        base += n*m - 1
    else:
        base += m*n - 1 + ((n-1)/K) * ((m-1)/K)
    print "Case #"+str(tt)+": "+str(base)

   

