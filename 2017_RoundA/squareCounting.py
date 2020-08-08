T=int(raw_input())
mod=int(1e9+7)

for tt in range(1,T+1):
    R,C=[int(t) for t in raw_input().split()]
    bound=min(R-1,C-1)
    s1=(1+bound)*bound/2%mod
    s2=bound*(bound+1)*(2*bound+1)/6%mod
    s3=bound*(bound+1)/2%mod
    s3=s3*s3%mod
    result=(s1*(R*C)%mod-(R+C)*s2%mod+s3+mod)%mod
    print "Case #"+str(tt)+": "+str(result)