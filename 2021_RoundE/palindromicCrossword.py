T = int(raw_input())
from collections import Counter, defaultdict
import copy
import heapq

def dfs(candidate, graph, result, seen, val):
    if candidate in seen:
        return 0
    count = 1
    seen.add(candidate)
    x, y = candidate
    result[x][y] = val
    for v in graph[candidate]:
        count += dfs(v, graph, result, seen, val)
    return count

for tt in range(1,T+1):
    M, N = [int(t) for t in raw_input().split()]
    grid = []
    for i in range(M):
        line = raw_input()
        grid.append(line+'#')
    grid.append('#'* (N+1))
    candidates = []
    graph = defaultdict(list)
    for i in range(M+1):
        seg = 0
        for j in range(N+1):
            if grid[i][j]!='#':
                seg += 1
                if grid[i][j]!='.':
                    candidates.append((i,j,grid[i][j]))
            else:
                left = j - seg 
                right = j-1
                if left >= 0:
                    while left < right:
                        graph[(i,left)].append((i,right))
                        graph[(i,right)].append((i,left))
                        left += 1
                        right -= 1
                seg = 0
    for j in range(N+1):
        seg = 0
        for i in range(M+1):
            if grid[i][j]!='#':
                seg += 1
            else:
                up = i - seg 
                down = i - 1
                if up >= 0:
                    while up < down:
                        graph[(up,j)].append((down,j))
                        graph[(down,j)].append((up,j))
                        up += 1
                        down -= 1
                seg = 0
    #print graph
    result = [[grid[x][y] for y in range(N)] for x in range(M)]
    seen = set()
    r = 0
    init = len(candidates)
    while candidates:
        x, y, val = candidates.pop()
        if (x,y) in seen:
            continue
        r += 1
        seen.add((x,y))
        result[x][y] = val
        for v in graph[(x,y)]:
            candidates.append((v[0], v[1], val))

    r -= init


    print "Case #"+str(tt)+": "+str(r)
    for row in result:
        print "".join(row)

