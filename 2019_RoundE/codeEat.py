import fileinput
from bisect import bisect_left

seq=1
caseNum=1

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

while seq<len(lines):
    D,S=lines[seq].split()
    D,S=int(D),int(S)
    a=[]
    for i in range(1,S+1):
        u,v=lines[seq+i].split()
        u=float(u)
        v=float(v)
        a.append([u,v])
    a.sort(key=lambda x:(x[1]/x[0]))
    cumCode=[]
    cumEat=[0]
    cum=0
    for t in a:
        cum+=t[0]
        cumCode.append(cum)

    for t in range(len(a)-1,-1,-1):
        cumEat.append(cumEat[-1]+a[t][1])

    #print cumCode
    #print cumEat 

    result=""
    for i in range(1,D+1):
        reqCode,reqEat=lines[seq+S+i].split()
        reqCode,reqEat=float(reqCode),float(reqEat)
        index=bisect_left(cumCode,reqCode)
        if index==len(cumCode):
            result+="N"
            continue
        else:
            excess=cumCode[index]-reqCode
            #print excess
            offer=excess*(a[index][1])/a[index][0]+cumEat[len(cumCode)-1-index]
            #print offer
            if offer>=reqEat:
                result+="Y"
            else:
                result+="N"


    print "Case #"+str(caseNum)+": "+str(result)
    seq+=S+D+1
    caseNum+=1
    