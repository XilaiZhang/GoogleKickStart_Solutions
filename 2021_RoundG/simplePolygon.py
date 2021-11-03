from collections import defaultdict
import sys
T=int(raw_input())

for tt in range(1,T+1):
    N, A = [int(x) for x in raw_input().split()]
    if A < N - 2:
        print "Case #"+str(tt)+": "+"IMPOSSIBLE"
        continue
    directions = [1, -1]
    currentDirection = 0
    count = 0
    px = 0
    py = 1
    if N == 3: #overflow
        py = 0
    up = []
    low = []
    while count < N :
        count += 1
        if count % 2 == 1:
            if currentDirection == 0:
                low.append([px,py])
            else:
                up.append([px, py])
            py += directions[currentDirection]
        else:
            if currentDirection == 0:
                up.append([px,py])
            else:
                low.append([px, py])
            px += 1
            currentDirection = 1 - currentDirection
            py += directions[currentDirection]
    extra = A - (N-2)
    up[0][1] += extra
    print "Case #"+str(tt)+": "+"POSSIBLE"
    for px, py in up:
        print str(px)+" "+str(py)
    for px, py in low[::-1]:
        print str(px)+" "+str(py)


