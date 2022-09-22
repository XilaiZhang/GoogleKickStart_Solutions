
T=int(input())
from collections import defaultdict, deque
from bisect import bisect, bisect_left, bisect_right

for tt in range(1,T+1):
    N, Q = [int(x) for x in input().split()]
    graph = defaultdict(lambda: [])
    for i in range(N-1):
        a, b = [int(x) for x in input().split()]
        graph[a].append(b)
        graph[b].append(a)
    q = deque([[1, 0]])
    geo = []
    seen = set()
    while q:
        current_node, depth = q.popleft()
        if current_node in seen:
            continue
        seen.add(current_node)
        if depth == len(geo):
            geo.append(0)
        geo[depth] += 1
        if current_node in graph:
            for kid in graph[current_node]:
                if kid not in seen:
                    q.append([kid, depth+1])

    for i in range(1,len(geo)):
        geo[i] += geo[i-1]

    for j in range(Q):
        _ = input()

    pos = bisect_left(geo, Q)
    result = -1
    if geo[pos] == Q:
        result = geo[pos]
    else:
        result = geo[pos - 1]
    
    print("Case #"+str(tt)+": "+str(result))
    

