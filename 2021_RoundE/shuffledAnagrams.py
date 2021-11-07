
from collections import defaultdict, Counter
T=int(raw_input())

for tt in range(1,T+1):
    S= raw_input()
    
    chars = []
    l = len(S)
    countMap = Counter(S)
    imposs = False
    for i in range(l):
        if countMap[S[i]] > l/2:
            imposs = True
            break
    if imposs:
        print "Case #"+str(tt)+": "+"IMPOSSIBLE"
        continue
    for i in range(l):
        chars.append([S[i], i])
    chars.sort()

    res = [None for x in range(l)]
    for i in range(l):
        if i < l/2:
            res[chars[i][1]] = chars[i + l/2][0]
        else:
            res[chars[i][1]] = chars[i - (l+1)/2][0]

    print "Case #"+str(tt)+": "+"".join(res)

   

