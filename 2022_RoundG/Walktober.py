T=int(input())

for tt in range(1,T+1):
    M, N, P = [int(x) for x in input().split()]
    max_steps = [0 for x in range(N)]
    my_steps = []
    for i in range(M):
        personal_steps = [int(x) for x in input().split()]
        for j in range(N):
            max_steps[j] = max(max_steps[j], personal_steps[j])
        if i == P-1:
            my_steps = personal_steps

    result = 0
    for i in range(N):
        result += max_steps[i] - my_steps[i]


    print("Case #"+str(tt)+": "+str(result))
    

