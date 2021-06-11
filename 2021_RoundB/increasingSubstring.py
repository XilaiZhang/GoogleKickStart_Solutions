
T=int(raw_input())

for tt in range(1,T+1):
    l=int(raw_input())
    word = raw_input()
    local = 1
    result=[ "1" for x in range(l)]
    for i in range(1, l):
        if word[i]>word[i-1]:
            local+=1
        else:
            local = 1
        result[i] = str(local)

    print "Case #"+str(tt)+": "+" ".join(result)

   

