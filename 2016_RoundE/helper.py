print 120
seq=1

def helper(startIndex,A):
    global seq
    if startIndex==4:
        C=[str(t) for t in A]
        print "5 2" #or "5 3" for large dataset
        print " ".join(C)
        seq+=1
        return
    for i in range(startIndex,5):
        A[i],A[startIndex]=A[startIndex],A[i]
        helper(startIndex+1,A)
        A[i],A[startIndex]=A[startIndex],A[i]

B=[1,2,3,4,5]
helper(0,B)