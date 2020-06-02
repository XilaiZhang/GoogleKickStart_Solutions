T=raw_input()
T=int(T)
import sys

def solve(number,op):
    exp=str(number)
    l=len(exp)
    k=0
    while k <l:
        if (int(exp[k]))%2==1:
            break
        k+=1
    result=0

    if k==l-1:
        return 1
    else:
        if k<l:
            up=sys.maxint
            down=sys.maxint
            if op%2==0:
                diff=10**(l-k-1)-int(exp[k+1:])
                up=diff+solve(number+diff,2)
            if op%3==0:
                diff=int(exp[k+1:])
                for t in range(k+1,l):
                    diff+=(10**(t-k-1))
                diff+=1
                down=diff+solve(number-diff,3)
            return min(up,down)

    return result


for t in range(1,T+1):
    N=raw_input()
    N=int(N)
    result=solve(N,0)

    print "Case #"+str(t)+": "+str(result)

    
        

