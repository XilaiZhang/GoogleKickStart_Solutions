from collections import defaultdict
import random
seen = defaultdict(int)
T=int(raw_input())

def compute(expression, left, right):
    global seen
    l = len(expression)
    if expression[left]!='(':
        return int(expression[left:right+1])
    p = 0
    j = left+1
    while j<=right:
        if expression[j] == '(':
            p+=1
        elif expression[j] == ')':
            p-=1
        elif p==0 and (expression[j]=='+' or expression[j] == '*' or expression[j] == '#'):
            lVal = compute(expression, left+1, j-1)
            rVal = compute(expression, j+1, right-1)
            #print("lVal is "+str(lVal)+" rVal is "+str(rVal))
            if expression[j]=='+':
                return lVal+rVal
            elif expression[j]=='*':
                return lVal*rVal
            elif expression[j]=='#':
                if (lVal, rVal) in seen:
                    return seen[(lVal, rVal)]
                else:
                    a = random.randint(1,(int)(1e17))
                    seen[(lVal, rVal)] = a
                    return a
        j+=1



for tt in range(1,T+1):
    seen.clear()
    groups = defaultdict()
    index = 1
    N=int(raw_input())
    result=""
    for i in range(N):
        line = raw_input()
        group = compute(line, 0 , len(line)-1)
        if group in groups:
            result+=" "+str(groups[group])
        else:
            groups[group]=index
            result+=" "+str(index)
            index+=1

    print "Case #"+str(tt)+":"+str(result)

   

