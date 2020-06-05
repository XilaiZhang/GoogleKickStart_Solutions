from collections import defaultdict
T=raw_input()
T=int(T)

def find(point,lookup):
    if point not in lookup:
        lookup[point]=point
        return point
    it=point
    while lookup[it]!=it:
        it=lookup[it]
    lookup[point]=it
    return it

def union(a,b,lookup,rank):
    p1=find(a,lookup)
    p2=find(b,lookup)
    if p1==p2:
        return False
    if rank[p1]<rank[p2]:
        lookup[p1]=p2
    else:
        lookup[p2]=p1
        if rank[p1]==rank[p2]:
            rank[p1]+=1
    return True



for tt in range(1,T+1):
    N=raw_input()
    N=int(N)
    numbers=[int(number) for number in raw_input().split()]
    values=[int(value) for value in raw_input().split()]

    q=[]
    for i in range(N):
        for j in range(i+1,N):
            q.append([min(numbers[i]^values[j],values[i]^numbers[j]),i,j])
    q.sort(key=lambda x:-x[0])

    count=N-1
    lookup=defaultdict()
    rank=defaultdict(lambda:0)
    result=0
    while count:
        weight,a,b=q.pop()
        if union(a,b,lookup,rank):
            count-=1
            result+=weight

    print "Case #"+str(tt)+": "+str(result)

    
        

