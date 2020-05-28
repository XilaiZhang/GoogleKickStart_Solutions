T=raw_input()
T=int(T)

def solve(F):
    end=F
    F=F-F%10
    start=F
    number=0
    p=0
    while F:
        y=F%10
        number+=y*(9**p)
        p+=1
        F/=10
    number=number*8/9
    for i in range(start,end+1):
        if "9" not in str(i) and i%9!=0:
            number+=1
    return number

for t in range(1,T+1):
    F,L=raw_input().split()
    F,L=int(F),int(L)
    result=solve(L)-solve(F)+1

    print "Case #"+str(t)+": "+str(result)

    
        

