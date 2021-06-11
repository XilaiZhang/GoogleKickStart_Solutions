import math
T=int(raw_input())

def testPrime(N):
    i=2
    while i*i<=N:
        if N%i==0:
            return False
        i+=1
    return True

for tt in range(1,T+1):
    Z=int(raw_input())
    mid = int(math.floor(math.sqrt(Z)))
    ref = mid
    firstSmall = -1
    secondSmall = -1
    while ref > 0:
        if testPrime(ref):
            if firstSmall<0:
                firstSmall = ref
            else:
                secondSmall = ref
                break
        ref -= 1
    ref = mid+1
    firstBig = -1
    #print str(firstSmall)+" "+str(secondSmall)
    while ref<Z:
        if testPrime(ref):
            firstBig=ref
            break
        ref+=1
    result = None
    if firstBig != -1 and firstBig*firstSmall<=Z:
        result = firstBig*firstSmall
    else:
        result = firstSmall * secondSmall
    print "Case #"+str(tt)+": "+str(result)

   

