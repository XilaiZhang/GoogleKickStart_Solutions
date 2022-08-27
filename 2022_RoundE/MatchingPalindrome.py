from asyncio import SubprocessTransport
import math
T=int(input())

def compute(coins, direction, dir):
    op = dir[direction][0]
    Kd = dir[direction][1]
    if op == '+':
        return coins + Kd
    elif op == '-':
        return coins - Kd
    elif op == '*':
        return coins * Kd
    elif op == '/':
        if coins == float('-inf'):
            return coins
        return math.floor(coins/Kd)
    else:
        raise Exception('not a valid operand')

for tt in range(1,T+1):
    N, P, M, Ar, Ac = [int(x) for x in input().split()]
    Ar -= 1
    Ac -= 1
    dir = [[0 for y in range(2)] for x in range(4)]
    # north, east, west, south. had to pay attention to the spec
    offsets = [[-1,0], [0,1],  [0, -1], [1,0]]
    for i in range(4):
        op, Kd = input().split()
        dir[i][0] = op
        dir[i][1] = int(Kd)
    customers = [[0 for y in range(11)] for x in range(11)]
    customer_id = {}
    for i in range(P):
        Xk, Yk, Ck = [int(x) for x in input().split()]
        customers[Xk-1][Yk-1] = Ck
        customer_id[(Xk-1, Yk-1)] = i

    dp = [[[[float('-inf') for sub in range((1<<10))] for step in range(M+1)] for y in range(N)] for x in range(N)]
    #initial state
    dp[Ar][Ac][0][0] = 0

    for step in range(1, M+1):
        for i in range(N):
            for j in range(N):
                for subset in range(1<<P):
                    #stay at same place and do nothing
                    dp[i][j][step][subset] = dp[i][j][step-1][subset]

                    # stay at same place, but delivers a pizza 
                    if customers[i][j] != 0:
                        Ck = customers[i][j]
                        mask = (1<<(customer_id[(i, j)]))
                        if (mask & subset)!=0:
                            prev_state = (subset ^ mask)
                            dp[i][j][step][subset] = max(dp[i][j][step][subset], dp[i][j][step-1][prev_state] + Ck)

                    #come from a neighboring place
                    for direction in range(4):
                        offset_i, offset_j = offsets[direction]
                        old_i, old_j = i - offset_i, j - offset_j
                        if old_i >=0 and old_i<N and old_j >=0 and old_j<N:
                            # come from a different place, but do not deliver a pizza
                            dp[i][j][step][subset] = max(dp[i][j][step][subset], compute(dp[old_i][old_j][step-1][subset], direction, dir))
                            if customers[i][j] != 0:
                                Ck = customers[i][j]
                                mask = (1<<(customer_id[(i, j)]))
                                if (mask & subset)!=0:
                                    prev_state = (subset ^ mask)
                                    # come from a different place, and delivers a pizza
                                    dp[i][j][step][subset] = max(dp[i][j][step][subset], compute(dp[old_i][old_j][step-1][prev_state], direction, dir) + Ck)
        # print("the value is set to "+str(dp[0][1][1][0]))
        # print("after step "+str(step)+" the dp looks like")
        # for u in range(N):
        #     for v in range(N):
        #         print(str(dp[u][v][step][0])+' '+str(dp[u][v][step][1])+' # ')
    result = float('-inf')
    all_set = (1<<P) - 1
    for i in range(N):
        for j in range(N):
            result = max(result, dp[i][j][M][all_set])

    if result == float('-inf'):
        print("Case #"+str(tt)+": "+"IMPOSSIBLE")
        continue
    
    print("Case #"+str(tt)+": "+str(result))
    

