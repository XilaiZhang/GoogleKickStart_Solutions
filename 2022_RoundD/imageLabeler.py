from collections import defaultdict, deque
T=int(input())   

for tt in range(1,T+1):
    N, M = [int(x) for x in input().split()]
    numbers = [int(x) for x in input().split()]
    numbers.sort(key = lambda x: -x)
    last_size = N-M+1
    if last_size % 2 ==0:
        start = numbers[M - 1 + int(max(last_size - 1, 0) / 2)]
        end = numbers[M - 1 + int(last_size / 2)]
        pivot = (start + end) / 2.0
    else:
        pivot = numbers[M - 1 + int(last_size/2)]
    numbers[M-1] = pivot
    res = sum(numbers[:M])
    print("Case #"+str(tt)+": "+str(res))

   

