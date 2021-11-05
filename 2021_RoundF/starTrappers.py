from collections import defaultdict
import sys
import math
T=int(raw_input())

# https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
def sign (p1, p2, p3):
    return (p1[0] - p3[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p3[1])


def PointInTriangle (pt, v1, v2, v3):

    d1 = sign(pt, v1, v2)
    d2 = sign(pt, v2, v3)
    d3 = sign(pt, v3, v1)

    has_neg = (d1 < 0) or (d2 < 0) or (d3 < 0)
    has_pos = (d1 > 0) or (d2 > 0) or (d3 > 0)
    on_side = (d1 == 0) or (d2 == 0) or (d3 == 0)

    return not (has_neg and has_pos) and not on_side

def computeDistance(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def computeDiameter(p1, p2, p3):
    r = 0
    r += computeDistance(p1, p2)
    r += computeDistance(p2, p3)
    r += computeDistance(p1, p3)
    return r

def computeDiameterFour(p1, p2, p3, p4):
    r = 0
    r += computeDistance(p1, p4)
    r += computeDistance(p2, p3)
    r += computeDistance(p1, p3)
    r += computeDistance(p2, p4)
    return r

def computeCoord(p1, origin):
    if p1[1] == origin[1]:
        if p1[0] > origin[0]:
            return 0
        else:
            return 2
    if p1[0] == origin[0]:
        if p1[1] > origin[1]:
            return 1
        else:
            return 3
    if p1[0] - origin[0] > 0:
        if p1[1] - origin[1] > 0:
            return 0
        else:
            return 3
    else:
        if p1[1] - origin[1] > 0:
            return 1
        else:
            return 2

def gcd(a,b):
    if a == 0:
        return b
    return gcd(b%a, a)

def computeHash(p1, o):
    Y = abs(p1[1] - o[1])
    X = abs(p1[0] - o[0])
    if X == 0 and Y == 0:
        return (0,0)
    if Y == 0:
        return (1, 0)
    elif X == 0:
        return (0, 1)
    else:
        g = gcd(Y, X)
        return (X/g, Y/g)
    

for tt in range(1,T+1):
    result = sys.maxint
    N = int(raw_input())
    points = []
    for i in range(N):
        a,b = [int(x) for x in raw_input().split()]
        points.append([a,b])
    blueX, blueY = [int(x) for x in raw_input().split()]
    origin = [blueX, blueY]

    for i in range(N):
        for j in range(i+1, N):
            for k in range(j+1, N):
                if PointInTriangle(origin, points[i], points[j], points[k]):
                    currentR = computeDiameter(points[i], points[j], points[k])
                    result = min(result, currentR)

    coordinates = [defaultdict() for x in range(4)]
    for point in points:
        coord = computeCoord(point, origin)
        hashKey = computeHash(point, origin)
        if hashKey not in coordinates[coord]:
            coordinates[coord][hashKey] = point
        else:
            oldPoint = coordinates[coord][hashKey]
            oldDist = computeDistance( oldPoint, origin)
            newDist = computeDistance( point, origin )
            if newDist < oldDist:
                coordinates[coord][hashKey] = point


    pointGroups = []
    for hashKey in coordinates[0]:
        if hashKey in coordinates[2]:
            pointGroups.append([coordinates[0][hashKey], coordinates[2][hashKey]])
    for hashKey in coordinates[1]:
        if hashKey in coordinates[3]:
            pointGroups.append([coordinates[1][hashKey], coordinates[3][hashKey]])

    l = len(pointGroups)
    for i in range(l):
        for j in range(i+1,l):
            currentR = computeDiameterFour(pointGroups[i][0], pointGroups[i][1], pointGroups[j][0], pointGroups[j][1] )
            result = min(result, currentR)

    if result == sys.maxint:
        print "Case #"+str(tt)+": "+"IMPOSSIBLE"
    else:
        print "Case #"+str(tt)+": "+str(result)


