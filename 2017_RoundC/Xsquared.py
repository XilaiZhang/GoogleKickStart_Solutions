from collections import Counter
T=raw_input()
T=int(T)

def solve():
    N=int(raw_input())
    rows=[[] for x in range(N)]
    cols=[[] for x in range(N)]
    for i in range(N):
        line=raw_input()
        for j in range(len(line)):
            if line[j]=="X":
                rows[i].append(j)
                cols[j].append(i)

    oneCount=0
    rowDict=Counter()
    colDict=Counter()
    for i in range(N):
        if len(rows[i])==1:
            oneCount+=1
        elif len(rows[i])!=2:
            return "IMPOSSIBLE"
        else:
            x,y=rows[i]
            rowDict[(x,y)]+=1
    if oneCount!=1:
        return "IMPOSSIBLE"

    oneCount=0
    for j in range(len(cols)):
        if len(cols[j])==1:
            oneCount+=1
        elif len(cols[j])!=2:
            return "IMPOSSIBLE"
        else:
            x,y=cols[j]
            colDict[(x,y)]+=1
    if oneCount!=1:
        return "IMPOSSIBLE"

    for key in rowDict:
        if rowDict[key]!=2:
            return "IMPOSSIBLE"
    for key in colDict:
        if colDict[key]!=2:
            return "IMPOSSIBLE"

    return "POSSIBLE"


for tt in range(1,T+1):
    result=solve()
    print "Case #"+str(tt)+": "+result

    
        

