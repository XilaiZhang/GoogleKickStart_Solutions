T=int(input())

for tt in range(1,T+1):
    N , X, Y= [int(x) for x in input().split()]
    my_sum = sum([x for x in range(1,N+1)])
    if (X+Y) > my_sum or my_sum % (X+Y) != 0:
        print("Case #"+str(tt)+": "+"IMPOSSIBLE")
    else:
        print("Case #"+str(tt)+": "+"POSSIBLE")
        my_sum = int(my_sum / (X+Y) * X)
        current_big = N
        res = []
        while my_sum > 0:
            if my_sum > current_big:
                res.append(current_big)
                my_sum -= current_big
                current_big -= 1
            elif my_sum <= current_big:
                res.append(my_sum)
                break
        print(len(res))
        print(" ".join([str(x) for x in res]))
    

