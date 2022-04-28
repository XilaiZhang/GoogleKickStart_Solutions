
T=int(input())

def isPal(A):
    A = str(A)
    l = 0
    r = len(A)-1
    while l<r:
        if A[l] == A[r]:
            l += 1
            r -= 1
        else:
            return False
    return True

for tt in range(1,T+1):
    A = int(input())
    x = 1
    res = 0
    while x*x <= A:
        if A % x == 0:
            B = int(A/x) 
            if isPal(x):
                res += 1
            if B!=x and isPal(B):
                res += 1

        x+=1

    print('Case #'+str(tt)+": "+str(res))


