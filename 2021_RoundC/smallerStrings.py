
T = int(raw_input())
mod = 1e9+7


for tt in range(1,T+1):
    N, K =[int(t) for t in raw_input().split()]
    word = raw_input()
    result = 0
    exp = [1]
    for u in range(N+1):
        exp += [int((exp[-1] * K) %mod)]

    bound = (N+1)/2
    mid = (N-1)/2
    for i in range(bound):
        char = word[i]
        result = int((result + (ord(char) - ord('a')) * exp[mid-i])%mod)
    
    if N%2 == 1:
        new = word[:mid]+word[mid]+word[:mid][::-1]
        if new<word:
            result = int((result + 1)%mod)
    else:
        new = word[:bound]+word[:bound][::-1]
        if new<word:
            result = int((result + 1)%mod)



    print "Case #"+str(tt)+": "+str(result)

   

