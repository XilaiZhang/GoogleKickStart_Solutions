
T = int(raw_input())

for tt in range(1,T+1):
    G = int(raw_input())
    G*=2
    i = 1
    result = 1
    while (i+1)*(i+1)<=G:
        if G%(i+1)!=0:
            i+=1
            continue
        else:
            left = G/(i+1)
            if left-i<=0:
                break
            if (left-i)%2==0:
                result+=1
            i+=1


    print "Case #"+str(tt)+": "+str(result)

   

