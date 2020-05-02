from collections import defaultdict
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    N,R,C,startR,startC=raw_input().split()
    N,R,C,startR,startC=int(N),int(R),int(C),int(startR),int(startC)
    colDict=defaultdict(lambda:defaultdict(lambda:0))
    rowDict=defaultdict(lambda:defaultdict(lambda:0))
    x=startR
    y=startC

    order=raw_input()
    for c in range(len(order)):
        if order[c]=="E":
            newX=x
            if not colDict[x][y+1]:
                newY=y+1
            else:
                newY=y+colDict[x][y+1]+1
        elif order[c]=="W":
            newX=x
            if not colDict[x][y-1]:
                newY=y-1
            else:
                newY=y-colDict[x][y-1]-1
        elif order[c]=="N":
            newY=y
            if not rowDict[y][x-1]:
                newX=x-1
            else:
                newX=x-rowDict[y][x-1]-1
        else:
            newY=y
            if not rowDict[y][x+1]:
                newX=x+1
            else:
                newX=x+rowDict[y][x+1]+1
        leftBound=0
        if y>1:
            leftBound=colDict[x][y-1]
        rightBound=0
        if y<C:
            rightBound=colDict[x][y+1]
        horiSegment=leftBound+rightBound+1
        colDict[x][y-leftBound]=horiSegment
        colDict[x][y+rightBound]=horiSegment

        upBound=0
        if x>1:
            upBound=rowDict[y][x-1]
        downBound=0
        if x<R:
            downBound=rowDict[y][x+1]
        vertiSegment=upBound+downBound+1
        rowDict[y][x-upBound]=vertiSegment
        rowDict[y][x+downBound]=vertiSegment
        x=newX
        y=newY
        #print str(newX)+" "+str(newY)
    #print rowDict
    print "Case #"+str(tt)+": "+str(x)+" "+str(y)


    