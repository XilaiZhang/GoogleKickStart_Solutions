from collections import defaultdict
T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    children=defaultdict(set)
    parent=defaultdict(set)
    names=set()
    for i in range(N):
        current,exp=raw_input().split("=")
        names.add(current)
        values=[t for t in exp.replace("(","#").replace(")","#").split("#")[1].split(",")]
        
        for val in values:
            children[val].add(current)
            parent[current].add(val)
            names.add(val)

    good=[]
    for name in parent:
        if len(parent[name])==1 and '' in parent[name]:
            good.append(name)

    arranged=set()
    while good:
        name=good.pop()
        arranged.add(name)
        for child in children[name]:
            if child in parent:
                parent[child].discard(name)
                if len(parent[child])==0:
                    good.append(child)
                    del parent[child]

    if len(names)==len(arranged)+1: #+1 for ''
        print "Case #"+str(tt)+": GOOD"
    else:
        print "Case #"+str(tt)+": BAD"