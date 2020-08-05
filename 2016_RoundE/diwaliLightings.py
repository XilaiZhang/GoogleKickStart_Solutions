from collections import Counter
T=int(raw_input())

for tt in range(1,T+1):
    S=raw_input()
    I,J=[int(t) for t in raw_input().split()]
    l=len(S)
    g1,r1=(I-1)/l,(I-1)%l
    g2,r2=(J-1)/l,(J-1)%l
    allDict=Counter(S)
    dict1=Counter(S[r1:])
    dict2=Counter(S[:r2+1])
    result=0
    if g1==g2:
        result=dict2["B"]-Counter(S[:r1])["B"]
    else:
        result+=dict1["B"]+allDict["B"]*(g2-g1-1)+dict2["B"]
    
    print "Case #"+str(tt)+": "+str(result)