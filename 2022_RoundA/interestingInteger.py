
from collections import defaultdict
T=int(input())

dp = [[[[[['*' for z in range(118) ] for u in range(3)] for v in range(3)] for w in range(5)] for x in range(8)] for p in range(14)]

#initialization
product = 1
for p2 in range(8):
    for p3 in range(5):
        for p5 in range(3):
            for p7 in range(3):
                dp[0][p2][p3][p5][p7][0] = 0
                if p2 == 0:
                    product = 0
                else:
                    product = (2**(p2-1)) * (3**p3) * (5**p5) * (7**p7)
                for S in range(1,118):
                    if product % S == 0:  
                        dp[0][p2][p3][p5][p7][S] = 1
                    else:
                        dp[0][p2][p3][p5][p7][S] = 0

resultMap = defaultdict()
f1Map = defaultdict()
breakUp = { # for exponential of 2, make it one more, e.g. 1 can't be divided by 2 but we still give it 1
    0: [0, -1, -1, -1],
    1: [1,0,0,0],
    2: [2,0,0,0],
    3: [1,1,0,0],
    4: [3,0,0,0],
    5: [1,0,1,0],
    6: [2,1,0,0],
    7: [1,0,0,1],
    8: [4,0,0,0],
    9: [1,2,0,0]
}

def f1(L, p2, p3, p5, p7, S):
    p2 = min(p2, 7)
    p3 = min(p3, 4)
    p5 = min(p5, 2)
    p7 = min(p7, 2)
    if p2 == 0:
        return 10**L if S>0 else 0

    if dp[L][p2][p3][p5][p7][S] != '*':
        return dp[L][p2][p3][p5][p7][S]
    count = 0
    #assume f1 is always safe to operate on things starting with 0
    for digit in range(0, 10):
        pp2, pp3, pp5, pp7 = breakUp[digit]
        if p2 == 0 or pp2 == 0:
            count += f1(L - 1, 0, p3 + pp3, p5 + pp5, p7 + pp7, S + digit)
        else:
            count += f1(L - 1, p2 + pp2 - 1, p3 + pp3, p5 + pp5, p7 + pp7, S + digit)
    dp[L][p2][p3][p5][p7][S] = count
    return count

def CountInterestingIntegersWithNumberOfDigits(L):
    if L == 1:
        return 9 # 0 to 9?
    count = 0
    for digit in range(1, 10):
        p2, p3, p5, p7 = breakUp[digit]
        count += f1(L - 1, p2, p3, p5, p7, digit)
    return count

def CountInterestingIntegersWithPrefixOfN(N, p2, p3, p5, p7, S, digit_index, is_first_digit):
    strN = str(N)
    l = len(str(N))
    if digit_index == l:
        if p2 == 0 or (S > 0 and ((2**(p2-1))*(3**p3)*(5**p5)*(7**p7)) % S == 0):
            return 1
        else:
            return 0

    if is_first_digit:
        digit_start = 1
    else:
        digit_start = 0

    count = 0
    for digit in range(digit_start, int(strN[digit_index])):
        pp2, pp3, pp5, pp7 = breakUp[digit]
        if p2 == 0 or pp2 == 0:
            count += f1(l - digit_index - 1, 0, p3 + pp3, p5 + pp5, p7 + pp7, S + digit)

        else:
            count += f1(l - digit_index - 1, p2 + pp2 - 1, p3 + pp3, p5 + pp5, p7 + pp7, S + digit)

    currentDigit = int(strN[digit_index])  
    pp2, pp3, pp5, pp7 = breakUp[currentDigit]
    newP2 = p2 + pp2 - 1
    if p2 == 0 or pp2 ==0 :
        newP2 = 0
    count += CountInterestingIntegersWithPrefixOfN(N, newP2, p3 + pp3, p5 + pp5, p7 + pp7,
                S + currentDigit, digit_index + 1, is_first_digit=False)
    return count

def CountInterestingIntegers(N):
    if N in resultMap:
        return resultMap[N]
    if N == 0:
        return 0
    numberLength = len(str(N))
    count = 0
    for L in range(1, numberLength): #the number itself
        count += CountInterestingIntegersWithNumberOfDigits(L)

    count += CountInterestingIntegersWithPrefixOfN(N, 1,0,0,0, 0, 0, True) #P=1, S=0, digit_index=0
    # offset power of 2 by 1, so that we can denote a product of 0
    # otherwise 2^0 * 3^0 .. = 1 and we can't represent 0
    resultMap[N] = count
    return count

for tt in range(1,T+1):
    A, B = input().split()
    A, B = int(A), int(B)
    res2 = CountInterestingIntegers(B)
    res1 = CountInterestingIntegers(A-1)
    res = "Case #"+str(tt)+": "+str(res2 - res1)
    print(res)

   

