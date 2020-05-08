
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    A,B=raw_input().split()
    A,B=int(A),int(B)
    N=raw_input()
    N=int(N)
    low=1
    high=B
    for t in range(N):
        mid=low+(high-low)/2
        print mid
        feedback=raw_input()
        if feedback=="CORRECT":
            break
        elif feedback=="TOO_SMALL":
            low=mid+1
        elif feedback=="TOO_BIG":
            high=mid-1
        
        

