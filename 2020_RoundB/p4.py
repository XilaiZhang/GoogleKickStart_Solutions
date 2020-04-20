import fileinput
import math
from collections import defaultdict

seq=0
caseNum=1

for line in fileinput.input():
    if not seq:
        seq+=1
        continue
    W,H,L,U,R,D=line.rstrip().split()
    W=int(W)
    H=int(H)
    L=int(L)
    U=int(U)
    R=int(R)
    D=int(D)
    factorial=defaultdict()
    factorial[0]=0
    f=0
    for i in range(1,max(U+R,L+D)):
        f+=math.log(i,2)
        factorial[i]=f
    
    result=0.0

    x=U-1
    y=R+1
    while x>0 and y<W:
        steps=x-1+y-1
        result+=2**(factorial[steps]-factorial[steps-x+1]-factorial[x-1]-steps)
        x-=1
        y+=1
    if y==W and x>0:
        for t in range(1,x+1):
            steps=t-1+W-2
            result+=2**(factorial[steps]-factorial[steps-t+1]-factorial[t-1]-steps-1)
    
    x=D+1
    y=L-1
    while x<H and y>0:
        steps=x-1+y-1
        result+=2**(factorial[steps]-factorial[steps-x+1]-factorial[x-1]-steps)
        x+=1
        y-=1
    if x==H and y>0:
        for t in range(1,y+1):
            steps=H-2+t-1
            result+=2**(factorial[steps]-factorial[steps-t+1]-factorial[t-1]-steps-1)

            #print result
    print("Case #"+str(caseNum)+": "+str(result))
    caseNum+=1
