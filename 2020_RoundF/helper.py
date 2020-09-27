from random import randint
print "100"
for T in range(100):
    myDict=set()
    n=0
    while n<12:
        x=randint(1,6)
        y=randint(1,2*x-1)
        if (x,y) in myDict:
            continue
        myDict.add((x,y))
        n+=1
    myDict=list(myDict)
    result="6 "+str(myDict[0][0])+" "+str(myDict[0][1])+" "+str(myDict[1][0])+" "+str(myDict[1][1])+\
    " 10"
    print result
    for i in range(2,12):
        print str(myDict[i][0])+" "+str(myDict[i][1])


