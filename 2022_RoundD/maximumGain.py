from collections import defaultdict, deque
T=int(input())   

for tt in range(1,T+1):
    N = int(input())
    a_array = [int(x) for x in input().split()]
    M = int(input())
    b_array = [int(x) for x in input().split()]
    K = int(input())

    prefix_a = [0]
    for a in a_array:
        prefix_a.append(prefix_a[-1] + a)
    postfix_a = [0]
    for i in range(N-1, -1, -1):
        postfix_a.append(postfix_a[-1] + a_array[i])

    prefix_b = [0]
    for b in b_array:
        prefix_b.append(prefix_b[-1] + b)
    postfix_b = [0]
    for i in range(M-1, -1, -1):
        postfix_b.append(postfix_b[-1] + b_array[i])

    result = 0
    for s1 in range( max(0, K-M), min(K+1, N+1)):
        s2 = K - s1
        sum_1 = 0
        for front in range(s1+1):
            sum_1 = max(sum_1, prefix_a[front] + postfix_a[s1 - front])
        sum_2 = 0
        for front in range(s2+1):
            sum_2 = max(sum_2, prefix_b[front] + postfix_b[s2 - front])
        result = max(result, sum_1 + sum_2)

    res = "Case #"+str(tt)+": "+str(result)
    print(res)

   

