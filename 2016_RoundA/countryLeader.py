from collections import Counter
T=int(raw_input())

for tt in range(1,T+1):
    N=int(raw_input())
    seq=[[] for x in range(27)]
    for i in range(N):
        word=raw_input()
        some=Counter(word.replace(' ',''))
        seq[len(some)].append(word)
    exp=26
    while len(seq[exp])==0:
        exp-=1
    seq[exp].sort()
    print "Case #"+str(tt)+": "+seq[exp][0]

    