import sys, heapq
from collections import defaultdict
T=int(raw_input())

def replenish(minHeap, maxHeap,minHeapSize, maxHeapSize, inMinHeap, inMaxHeap, currentR, K):
    while minHeapSize[0] < K and maxHeapSize[0] > 0:
        while maxHeap[0][1] in invalid:
            heapq.heappop(maxHeap)
        oldVal, oldId = heapq.heappop(maxHeap)
        oldVal = -oldVal
        maxHeapSize[0] -= 1
        inMaxHeap.discard(oldId)
        heapq.heappush(minHeap, [oldVal, oldId])
        minHeapSize[0] +=1
        inMinHeap.add(oldId)
        currentR[0] += oldVal
    
def addToMinHeap(minHeap, minHeapSize, inMinHeap, currentR, hVal, eid):
    heapq.heappush(minHeap, [hVal, eid])
    minHeapSize[0] += 1
    inMinHeap.add(eid)
    currentR[0] += hVal

def addToMaxHeap(maxHeap, maxHeapSize, inMaxHeap, hVal, eid):
    heapq.heappush(maxHeap, [-hVal, eid])
    maxHeapSize[0] += 1
    inMaxHeap.add(eid)

def removeTopMinHeap(minHeap, minHeapSize, inMinHeap, currentR, maxHeap, maxHeapSize, inMaxHeap):
    oldVal, oldId = heapq.heappop(minHeap)
    minHeapSize[0] -= 1
    inMinHeap.discard(oldId)
    currentR[0] -= oldVal
    addToMaxHeap(maxHeap, maxHeapSize, inMaxHeap, oldVal, oldId)

for tt in range(1,T+1):
    D, N, K=[int(k) for k in raw_input().split()]
    events = []
    for i in range(N):
        happy, start, end = [int(k) for k in raw_input().split()]
        events.append([start, happy, 's', i])
        events.append([end+1, -happy, 'e', i])
    events.sort()

    minHeap = []
    maxHeap = []
    minHeapSize = [0]
    maxHeapSize = [0]
    inMaxHeap = set()
    inMinHeap = set()
    result = 0
    idx = 0
    l = len(events)
    invalid = set()
    currentR = [0]

    while idx < l:
        it = idx
        while it < l and events[it][0] == events[idx][0]:
            it += 1
        if events[idx][0] > D:
            break
        currentTime = events[idx][0]
        for k in range(idx, it):
            time, hVal, op, eid = events[k]
            if op == 's':
                if minHeapSize[0] < K:
                    replenish(minHeap, maxHeap,minHeapSize, maxHeapSize, inMinHeap, inMaxHeap,
                                currentR, K)

                while minHeap and minHeap[0][1] in invalid:
                    heapq.heappop(minHeap)
                if minHeapSize[0]== 0 or minHeapSize[0]<K:
                    addToMinHeap(minHeap, minHeapSize, inMinHeap, currentR, hVal, eid)
                elif minHeap[0][0] >= hVal:
                    addToMaxHeap(maxHeap, maxHeapSize, inMaxHeap, hVal, eid)
                elif minHeap[0][0] < hVal:
                    removeTopMinHeap(minHeap, minHeapSize, inMinHeap, currentR, maxHeap, maxHeapSize, inMaxHeap)
                    addToMinHeap(minHeap, minHeapSize, inMinHeap, currentR, hVal, eid)

            elif op == 'e':
                invalid.add(eid)
                if eid in inMinHeap:
                    currentR[0] += hVal
                    minHeapSize[0] -= 1
                    replenish(minHeap, maxHeap,minHeapSize, maxHeapSize, inMinHeap, inMaxHeap,
                                currentR, K)

                elif eid in inMaxHeap:
                    maxHeapSize[0] -= 1
        result = max(result, currentR[0])       
        idx = it

    print "Case #"+str(tt)+": "+str(result)

   

