from collections import defaultdict
T=int(input())

for tt in range(1,T+1):
    N, L = [int(x) for x in input().split()]
    dir = [None for x in range(N)]
    event = []
    ant_array = []
    for i in range(N):
        position, direction = [int(x) for x in input().split()]
        if direction == 0:
            event.append([position, 0])
        else:
            event.append([L - position, 1])
        ant_array.append([position, i+1])
    event.sort()
    ant_array.sort()

    p1 = 0
    p2 = N-1
    res = ''

    fall_array = []
    for e in event:
        time, side = e
        if side == 0:
            fall_array.append([time, ant_array[p1][1]])
            p1 += 1
        else:
            fall_array.append([time, ant_array[p2][1]])
            p2 -= 1
    fall_array.sort()
    res = "Case #"+str(tt)+": "+" ".join([str(x[1]) for x in fall_array])
    print(res)

   

