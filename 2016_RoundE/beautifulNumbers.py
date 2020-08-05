T=int(raw_input())

def compute(base,p):
    ans=1
    while p>0:
        if (p & 1):
            ans*=base
        p/=2
        base=base*base
    return ans

for tt in range(1,T+1):
    A=int(raw_input())
    result=A-1
    for N in range(2,65):
        low=2
        high=A
        while low<high:
            mid=low+(high-low)/2
            cal=compute(mid,(N+1))-1-A*mid+A
            if cal>0:
                high=mid
            elif cal<0:
                low=mid+1
            else:
                result=min(result,mid)
                break
    print "Case #"+str(tt)+": "+str(result)