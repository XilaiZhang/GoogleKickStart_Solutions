from collections import defaultdict
T=int(raw_input())

for tt in range(1,T+1):
    N,X=[int(t) for t in raw_input().split()]
    intervals=[]
    for i in range(N):
        s,t=[int(t) for t in raw_input().split()]
        intervals.append([s,t])
    intervals.sort()
    result=1
    coverage=intervals[0][0]+X
    for i in range(N):
        a,b=intervals[i]
        if coverage>=b:
            continue
        if coverage<a:
            coverage=a
        q=(b-coverage-1)/X+1
        result+=q
        coverage=coverage+q*X



    
    print "Case #"+str(tt)+": "+str(result)
        

