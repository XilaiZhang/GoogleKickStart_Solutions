import math
T=raw_input()
T=int(T)

def isPalindrome(l,begin=0,end=None):
    if end is None:
        end=len(l)-1
    if end-begin+1<=1:
        return True
    i=begin
    j=end
    while i<j:
        if l[i]!=l[j]:
            return False
        i+=1
        j-=1
    return True

def compute(l,prefix,N,choices):
    count=0
    for r in range(l+1,N+1):
        if l*2>=r:
            if isPalindrome(prefix,r-l,l-1):
                count+=1
        else:
            count+=choices**((r-2*l+1)/2)
    return count
        
for tt in range(1,T+1):
    L,N,K=raw_input().split()
    L,N,K=int(L),int(N),int(K)
    result=0
    if K<=N:
        print "Case #"+str(tt)+": "+str(K)
        continue
    if L==1:
        print "Case #"+str(tt)+": "+"0"
        continue
    start=max(0,int((N+1)/2-math.log(K,L)))  #precision of float or double might be a problem, debug took so long
    remainder=K-2*start

    if remainder==0:
        print "Case #"+str(tt)+": "+str(2*start)
        continue
    prefix=""
    done=False
    while remainder and not done: 
        for off in range(L+1):
            if off==L:
                result=0
                done=True
                break
            c=chr(ord('a')+off)
            if isPalindrome(prefix+c):
                if remainder==1:
                    result=2*start+len(prefix)+1
                    done=True
                    break
                remainder-=1
            kid=compute(len(prefix)+1,prefix+c,N-2*start,L)
            if remainder>kid:
                remainder-=kid
            else: #if kid>=remainder
                prefix+=c
                break
    print "Case #"+str(tt)+": "+str(result)

    
        

