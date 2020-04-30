import fileinput
from bisect import bisect

caseNum=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

maxR=1
for seq in range(1,len(lines)):
    L,R=lines[seq].split()
    L,R=int(L),int(R)
    lines[seq]=[L,R]
    maxR=max(maxR,R)

bound=int(maxR**0.5)
A=[True for i in range(bound+1)]
B=[]   #primes including 2
for x in range(2, bound+1):
    if not A[x]:
        continue
    else:
        B.append(x)
        it=x**2
        while it<=bound:
            A[it]=False
            it+=x

def calc(low,high):
    if low>high:
        return 0
    A=[True for i in range(high-low+1)]
    count=0
    for p in B:
        s=(low/p)*p
        if s<low:
            s+=p
        while s<=high:
            if s!=p:
                A[s-low]=False
            s+=p
    #print A
    for x in range(low,high+1):
        if A[x-low] and x>2:
            count+=1
    return count

#print B

for seq in range(1,len(lines)):
    L,R=lines[seq]
    result=0   #number is 1
    case1=0
    if 1>=L and 1<=R:
        case1+=1
    #case1+=A[R]-A[L-1]
    case1+=calc(L,R)
    L1=L
    while L1%4!=2:
        L1+=1
    case2=0
    if R>=L1:
        case2=(R-L1)/4+1
    case3=0
    if L<=4 and 4<=R:
        case3+=1
    L2=L
    while L2%4!=0:
        L2+=1
    R2=R
    while R2%4!=0:
        R2-=1
    if L2<=R2:
        L2/=4
        R2/=4
        case3+=calc(L2,R2)
    case4=0
    if 8>=L and 8<=R:
        case4+=1
    result=case1+case2+case3+case4

    #print str(case1)+" "+str(case2)+" "+str(case3)+" "+str(case4)
    print "Case #"+str(caseNum)+": "+str(result)
    caseNum+=1

    