import fileinput
from collections import defaultdict

seq=1
caseNum=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

while seq<len(lines):
    N=int(lines[seq])
    vals=[int(t) for t in lines[seq+1].split()]
    seen=set()
    neighbors=[[] for x in range(N+1)]
    for j in range(seq+2,seq+N+1):
        a,b=lines[j].split()
        a=int(a)
        b=int(b)
        neighbors[a].append(b)
        neighbors[b].append(a)

    children=defaultdict(list)

    q=[[1]]
    index=0
    tmp=[]
    while index<len(q):
        for num in q[index]:
            seen.add(num)
            for n in neighbors[num]:
                if n not in seen:
                    children[num].append(n)
                    tmp.append(n)
        if tmp:
            q.append(tmp)
        index+=1
        tmp=[]

    states=[[0 for state in range(5)] for v in range(N+1)]
    #1 for light light, 2 for light,dark, 3 for dark light, 4 for dark dark
    

    for i in range(len(q)-1,-1,-1):
        for number in q[i]:
            if len(children[number])==0:
                states[number][1]=vals[number-1]
                states[number][2]=vals[number-1]
                states[number][3]=vals[number-1]
                # dark dark is 0
            else:
                sumA=0
                sumB=0
                allDark=0
                oneLightAllDark="#"
                for child in children[number]:
                    a=max(states[child][1],states[child][2])
                    b=max(states[child][3],states[child][4])
                    sumA+=a
                    sumB+=b
                    if oneLightAllDark=="#":
                        oneLightAllDark=states[child][3]
                    else:
                        oneLightAllDark=max(allDark+states[child][3],oneLightAllDark+max(states[child][4],states[child][3]))
                    allDark+=states[child][4]
                states[number][1]=sumA+vals[number-1]
                states[number][2]=sumB+vals[number-1]
                states[number][3]=sumA+vals[number-1]
                states[number][4]=max(allDark,vals[number-1]+oneLightAllDark)
    
    print states
    result=max(states[1][3],states[1][4])

    print "Case #"+str(caseNum)+": "+str(result)
    seq+=N+1
    caseNum+=1
    