
from collections import defaultdict
import heapq
T=int(raw_input())

class node:
    def __init__(self, x, i):
        self.prev = None
        self.next = None
        self.val = x
        self.idx = i

for tt in range(1,T+1):
    N = int(raw_input())
    S = raw_input()
    idxToNode = defaultdict()
    head = node(-1, -1)
    prevNode = head
    prevChar = '%'
    positions = defaultdict(set)
    for idx, char in enumerate(S):
        myNode = node(ord(char) - ord('0'), idx)
        idxToNode[ idx ] = myNode
        myNode.prev = prevNode
        prevNode.next = myNode
        prevNode = myNode
        if ord(char) == ord(prevChar) + 1 or (char == '0' and prevChar == '9'):
            positions[ ord(prevChar) - ord('0') ].add(idx - 1)
        prevChar = char
    tailNode = node(-1, -1)
    prevNode.next = tailNode

    
    while True: 
        hasNew = False
        for iteration in range(10):
            c1 = iteration
            if c1 == 9:
                c2 = 0
            else:
                c2 = c1 + 1

            for pos in positions[iteration]:
                if pos not in idxToNode:
                    continue
                currentNode = idxToNode[pos]
                if currentNode.val == c1 and currentNode.next.val == c2:
                    hasNew = True
                    idxToNode.pop( currentNode.next.idx, None)
                    currentNode.val = (currentNode.val + 2) % 10
                    if currentNode.prev.val == currentNode.val -1 or currentNode.prev.val == currentNode.val + 9:
                        positions[currentNode.prev.val].add(currentNode.prev.idx)

                    currentNode.next = currentNode.next.next
                    currentNode.next.prev = currentNode
                    if currentNode.val == currentNode.next.val -1 or currentNode.val == currentNode.next.val + 9:
                        positions[currentNode.val].add(currentNode.idx)
                    
            positions[iteration] = set()

        if not hasNew:
            break

    
    res = "Case #"+str(tt)+": "
    while head.next.idx != -1:
        res += chr(head.next.val + ord('0'))
        head = head.next
    print res

   

