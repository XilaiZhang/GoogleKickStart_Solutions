import fileinput
from bisect import bisect

caseNum=1
seq=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

while seq<len(lines):
    N,Q=lines[seq].split()
    N,Q=int(N),int(Q)
    numbers=[int(t) for t in lines[seq+1].split()]
    odds=[]
    total=0
    for j in range(len(numbers)):
        total^=numbers[j]
        count=0
        for i in range(10):
            if (numbers[j] & (1<<i)):
                count+=1
        if count%2==1:
            odds.append(j)

    result=""
    for i in range(Q):
        pos,val=lines[seq+2+i].split()
        pos,val=int(pos),int(val)
        index=bisect(odds,pos)
        count=0
        for i in range(10):
            if (val & (1<<i)):
                count+=1
        if index>0 and odds[index-1]==pos:
            if count%2==0:
                del odds[index-1]
        else:
            if count%2==1:
                odds.insert(index,pos)
        total^=numbers[pos]
        total^=val
        numbers[pos]=val
        
        ones=0
        for i in range(10):
            if (total & (1<<i)):
                ones+=1
        if ones%2==0:
            result+=" "+str(N)
        else:
            if not odds:
                result+=" 0"
            else:
                raw=max(N-1-odds[0], odds[-1])
                result+=" "+str(raw)


    print "Case #"+str(caseNum)+":"+str(result)
    seq+=2+Q
    caseNum+=1

    