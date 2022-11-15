import math
T=int(input())

for tt in range(1,T+1):
    # offset is the offset regarding starting line based on current direction
    offset = 0
    # prev is the previous direction of the run
    prev = 0
    # direction when last passed starting line
    lap_direction = 0
    result = 0
    L, N = [int(x) for x in input().split()]
    for i in range(N):
        distance, direction = input().split()
        distance = int(distance)
        if i == 0:
            lap_direction = direction
            laps = math.floor(distance / L)
            result += laps
            offset = distance % L
            prev = direction
            continue

        if direction == prev:
            offset += distance
            if offset < L:
                prev = direction
            elif offset >= L:
                laps = math.floor(offset / L)
                result += laps
                if direction != lap_direction:
                    result -= 1
                lap_direction = direction
                offset = offset % L
                prev = direction
        else:
            if distance < offset:
                complement = offset - distance
                offset = L - complement
                prev = direction
            elif distance >= offset:
                distance -= offset
                prev = direction
                if direction == lap_direction:
                    result += 1
                lap_direction = direction
                offset = distance
                result += math.floor(offset / L)
                offset = offset % L

    print("Case #"+str(tt)+": "+str(result))
    

