import fileinput
from collections import defaultdict

seq=0
caseNum=1

for line in fileinput.input():
    if not seq:
        seq+=1
        continue
    numbers=line.rstrip().split()
    total=0
    digitSum=0
    bigNum=0
    for i in range(len(numbers)):
        numbers[i]=int(numbers[i])
        if numbers[i]>20:
            numbers[i]=20+(numbers[i]&1)
        total+=numbers[i]
        if numbers[i]>9:
            bigNum+=1
        digitSum+=numbers[i]*(i+1)
    numbers.insert(0,0)

    if bigNum>1:
        print "Case #"+str(caseNum)+": "+"YES"
        caseNum+=1
        seq+=1
        continue

    digitSum%=11
    if digitSum%2==1:
        digitSum=(digitSum+11)/2
    else:
        digitSum=digitSum/2

    dp=[[0 for z in range(11)]for y in range(total/2+1)]

    for t in range(min(total/2+1,numbers[1]+1)):
        dp[t][t%11]=1
    for x in range(2,10):
        for y in range(total/2,-1,-1):
            for z in range(11):
                for count in range(min(numbers[x]+1,y+1)):
                    currentMod=(count*x)%11
                    if dp[y-count][(z-currentMod)%11]==1:
                        dp[y][z]=1
                        break

    #print dp
    result="NO"
    if dp[total/2][digitSum]:
        result="YES"
    print "Case #"+str(caseNum)+": "+result
    caseNum+=1
    