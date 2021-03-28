T=int(raw_input())

for tt in range(1,T+1):
    R,C = [int(t) for t in raw_input().split()]
    
    top=[0 for x in range(C)]
    left = [0 for x in range(C)]
    right = [0 for x in range(C)] 
    grid = []

    result=0
    for i in range(R):
        line=raw_input().split()
        if line[0]=="1":
            left[0]=1
            top[0]+=1
        else:
            left[0]=0
            top[0]=0
        for j in range(1,C):
            if line[j]=="1":
                top[j]+=1
                left[j]=left[j-1]+1
            else:
                top[j]=0
                left[j]=0
        if line[-1]=="1":
            right[C-1]=1
        else:
            right[C-1]=0
        for j in range(C-2,-1,-1):
            if line[j]=="1":
                right[j]=right[j+1]+1
            else:
                right[j]=0
        for j in range(C):
            result+=max(min(left[j]-1, top[j]/2-1),0)
            result+=max(min(right[j]-1, top[j]/2-1),0)
            result+=max(min(left[j]/2-1, top[j]-1),0)
            result+=max(min(right[j]/2-1, top[j]-1),0)
            #print "result is now "+str(result)
        grid.append(line)

    top=[0 for x in range(C)]
    left = [0 for x in range(C)]
    right = [0 for x in range(C)] 
    for i in range(R-1,-1,-1):
        if grid[i][0]=="1":
            left[0]=1
            top[0]+=1
        else:
            left[0]=0
            top[0]=0
        for j in range(1,C):
            if grid[i][j]=="1":
                top[j]+=1
                left[j]=left[j-1]+1
            else:
                top[j]=0
                left[j]=0
        if grid[i][-1]=="1":
            right[C-1]=1
        else:
            right[C-1]=0
        for j in range(C-2,-1,-1):
            if grid[i][j]=="1":
                right[j]=right[j+1]+1
            else:
                right[j]=0
        for j in range(C):
            result+=max(min(left[j]-1, top[j]/2-1),0)
            result+=max(min(right[j]-1, top[j]/2-1),0)
            result+=max(min(left[j]/2-1, top[j]-1),0)
            result+=max(min(right[j]/2-1, top[j]-1),0)
            #print "result is now "+str(result)
    
    print "Case #"+str(tt)+": "+str(result)





    







        

