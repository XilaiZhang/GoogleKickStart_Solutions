
T=int(input())

def checkPalindrome(S, i):
    left = i
    right = len(S)-1
    while left < right:
        if S[left] == S[right]:
            left += 1
            right -= 1
        else:
            return False
    return True

for tt in range(1,T+1):
    N = int(input())
    S = input()
    result = N
    for i in range(1,N+1):
        if N%i==0 and checkPalindrome(S, i):
                result = i
                break
    
    print("Case #"+str(tt)+": "+str(S[:i][::-1]))
    

