
T=int(input())

for tt in range(1,T+1):

    Rs, Rh = [int(x) for x in input().split()]
    N = int(input())
    stones = []
    for i in range(N):
        X, Y = [int(x) for x in input().split()]
        stones.append([X, Y, 0, X**2 + Y**2])

    M = int(input())
    for i in range(M):
        X, Y = [int(x) for x in input().split()]
        stones.append([X, Y, 1, X**2 + Y**2])

    stones.sort(key=lambda x: x[3])
    scores = [0, 0]
    if len(stones)>0:
        color = stones[0][2]
    maxR = (Rs + Rh)**2
    for stone in stones:
        if stone[2] != color or stone[3] > maxR:
            break
        else:
            scores[stone[2]] += 1


    print("Case #"+str(tt)+": "+str(scores[0])+" "+str(scores[1]))
    

