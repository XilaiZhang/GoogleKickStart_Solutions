
T=int(raw_input())

def compute(numbers):
    result = 2
    i=0

    while i<l-1:
        a = numbers[i]
        diff = numbers[i+1]-a
        j = i+2
        useOne = False
        jump = i+1
        while j<l:
            if numbers[j] == a+(j-i)*diff:
                j+=1
            else:
                if not useOne:
                    jump = j-1
                    useOne = True
                    j+=1
                else:
                    result = max(result, j-i)
                    break
        if j==l:
            result=max(result, j-i)
            break
        i = jump
    return result

for tt in range(1,T+1):
    l=int(raw_input())
    numbers = [int(x) for x in raw_input().split()]
    r = compute(numbers)
    numbers2 = numbers[::-1]
    r2 = compute(numbers2)
    result=max(r,r2)

    print "Case #"+str(tt)+": "+str(result)

   

