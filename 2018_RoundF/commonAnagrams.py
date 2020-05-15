
T=raw_input()
T=int(T)

for tt in range(1,T+1):
    L=raw_input()
    L=int(L)
    a=raw_input()
    b=raw_input()
    lookup=set()
    result=0
    for i in range(L):
        val=[0 for x in range(26)]
        for j in range(i,L):
            val[ord(b[j])-ord('A')]+=1
            lookup.add(tuple(val))
    #print lookup
    for i in range(L):
        val=[0 for x in range(26)]
        for j in range(i,L):
            val[ord(a[j])-ord('A')]+=1
            if tuple(val) in lookup:
                result+=1

    print "Case #"+str(tt)+": "+str(result)

    
        

