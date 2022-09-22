
T=int(input())
import math

for tt in range(1,T+1):
    N = int(input())
    fabrics = []
    for i in range(N):
        color, durability, id = input().split()
        durability, id = int(durability), int(id)
        fabrics.append([color, durability, id])
    arr_1 = sorted(fabrics, key = lambda x:(x[0], x[2]))
    arr_2 = sorted(fabrics, key = lambda x:(x[1], x[2]))
    result = 0
    for i in range(N):
        if arr_1[i] == arr_2[i]:
            result += 1
    
    print("Case #"+str(tt)+": "+str(result))
    

