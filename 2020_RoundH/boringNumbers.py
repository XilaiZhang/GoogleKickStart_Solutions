from collections import defaultdict
from bisect import bisect_left
T=int(raw_input())

prefix=[0 for x in range(19)]
val=[0 for x in range(19)]

currentSum=1
for i in range(1,19):
    currentSum*=5
    val[i]=currentSum
    prefix[i]=prefix[i-1]+currentSum

A=[1,3,5,7,9]
B=[0,2,4,6,8]

def compute(number):
    n=str(number)
    l=len(n)

    r=0
    r+=prefix[l-1]

    prevNum=1
    for j in range(l):
        ref=int(n[j])
        if (j&1):
            index=bisect_left(B,ref)
            if j==l-1:
                r+=index
            else:
                r+=index*val[l-j-1]
            if index==5 or B[index]>ref:
                break #greater than current val
            if j==l-1:
                r+=1 #acouunt for the last number
        else:
            if ref==0:
                break #nothing to do if smaller than 1
            index=bisect_left(A,ref)
            if j==l-1:
                r+=index
            else:
                r+=index*val[l-j-1]
            if index==5 or A[index]>ref:
                break #greater than current val
            if j==l-1:
                r+=1 #acouunt for the last number
    return r




for tt in range(1,T+1):
    L,R=[int(t) for t in raw_input().split()]
    result= compute(R)-compute(L-1)
    
    print "Case #"+str(tt)+": "+str(result)
        

