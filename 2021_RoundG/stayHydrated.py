
T=int(raw_input())

def sortAndFind(array, K):
    array.sort()
    idx = 0
    numSmall = 0
    numBig = K
    while idx < K:
        rightBound = idx
        while rightBound < K and array[rightBound][0] == array[idx][0]:
            rightBound += 1
        for j in range(idx, rightBound):
            if array[idx][1] == 'e':
                numSmall += 1
            else:
                numBig -= 1
        if numBig <= numSmall:
            break
        idx = rightBound
    return array[idx][0]


for tt in range(1,T+1):
    K = int(raw_input())
    xArray = []
    yArray = []
    for i in range(K):
        x1, y1, x2, y2 = [int(x) for x in raw_input().split()]
        xArray.append([x1, 's'])
        xArray.append([x2, 'e'])
        yArray.append([y1, 's'])
        yArray.append([y2, 'e'])

    rx = sortAndFind(xArray, K)
    ry = sortAndFind(yArray, K)

    print "Case #"+str(tt)+": "+str(rx)+" "+str(ry)
