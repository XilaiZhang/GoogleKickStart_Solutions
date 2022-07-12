
T=int(input())

for tt in range(1,T+1):
    N = int(input())
    target = [-1] + [int(x) for x in input().split(' ')]
    M = int(input())
    keyboard = [-1] + [int(x) for x in input().split(' ')]
    
    left_array = [-1 for x in range(M+2)]
    right_array = [-1 for x in range(M+2)]

    dp = [[float("inf") for y in range(M+1)] for x in range(N+1)]
    for j in range(1, M+1):
        if keyboard[j] == target[1]:
            dp[1][j] = 0
            left_array[j] = 0
        else:
            if left_array[j-1] == -1:
                left_array[j] = -1
            else:
                left_array[j] = left_array[j-1] + 1

    for j in range(M, 0, -1):
        if keyboard[j] == target[1]:
            right_array[j] = 0
        else:
            if right_array[j+1] == -1:
                right_array[j] = -1
            else:
                right_array[j] = right_array[j+1] + 1

    for i in range(2, N+1):
        next_left_array = [-1 for x in range(M+2)]
        next_right_array = [-1 for x in range(M+2)]
        for j in range(1, M+1):
            if keyboard[j] == target[i]:
                dist_left = left_array[j]
                leftmost = j - dist_left
                dist_right = right_array[j]
                rightmost = j + dist_right
                if dist_left != -1:
                    dp[i][j] = min(dp[i][j], dp[i-1][leftmost] + dist_left)
                if dist_right != -1:
                    dp[i][j] = min(dp[i][j], dp[i-1][rightmost] + dist_right)

                next_left_array[j] = 0
                next_right_array[j] = 0
            else:
                if next_left_array[j-1] == -1:
                    next_left_array[j] = -1
                else:
                    next_left_array[j] = next_left_array[j-1] + 1

        for j in range(M, 0, -1):
            if keyboard[j] != target[i]:
                if next_right_array[j+1] == -1:
                    next_right_array[j] = -1
                else:
                    next_right_array[j] = next_right_array[j+1] + 1

        left_array = next_left_array
        right_array = next_right_array

    result = float("inf")
    for x in dp[N]:
        if x != -1:
            result = min(result, x)

    print("Case #"+str(tt)+": "+str(result))
    

