
T=int(input())
inf = int(1e18)
dp = [[[inf for z in range(2)] for y in range(401)] for x in range(401)]

def compute(start, end, fromLeft, numbers, D):
    if start > end:
        return 0
    if dp[start][end][fromLeft] != inf:
        return dp[start][end][fromLeft]
    
    count = 0 
    if fromLeft == 0:
        if start != 0:
            count = numbers[start-1]

    else:
        if end != len(numbers)-1:
            count = numbers[end+1]
    
    startVal = (numbers[start] - count + D)%D
    endVal = (numbers[end] - count + D) %D
    operations = min(startVal, D-startVal)
    val1 = operations + compute(start+1, end, 0, numbers, D)
    operations = min(endVal, D-endVal)
    val2 = operations + compute(start, end-1, 1, numbers, D)
    val = min(val1, val2)
    dp[start][end][fromLeft] = val
    return val

for tt in range(1,T+1):
    N, D = [int(x) for x in input().split()]
    numbers = [int(x) for x in input().split()]
    dp = [[[inf for z in range(2)] for y in range(401)] for x in range(401)]
    res = compute(0,N-1,0,numbers, D)

    print('Case #'+str(tt)+": "+str(res))


