from collections import defaultdict

T=int(input())

def palindrome5(r, left, right):
    while left < right:
        if ((r & (1<<left))>>left) != ((r & (1<<right))>>right):
            return False
        left += 1
        right -= 1
    return True

def dfs(s, start, r, state):
    if start == 5:
        if not palindrome5(r, 0, 4):
            state[r] = True
        return

    if s[start] == '0':
        dfs(s, start+1, r, state)
    elif s[start] == '1':
        dfs(s, start+1, r | (1<<start), state)
    else:
        dfs(s, start+1, r, state)
        dfs(s, start+1, r | (1<<start), state)

def findPossible(s, start, state):
    for start in range(5, len(s)):
        newState = [False for x in range(1<<5)]

        for i in range(1<<5):
            if state[i] and (s[start] == '?' or s[start] == '1'):
                sixDigit = (i | (1<<5))
                if (not palindrome5(sixDigit, 1, 5)) and (not palindrome5(sixDigit, 0, 5)):
                    newState[(sixDigit >> 1)] = True
            if state[i] and (s[start] == '?' or s[start] == '0'):
                sixDigit = i
                if (not palindrome5(sixDigit, 1, 5)) and (not palindrome5(sixDigit, 0, 5)):
                    newState[(sixDigit >> 1)] = True
        state = newState

    # start == len(s):
    for i in range(1<<5):
        if state[i]:
            return 'POSSIBLE'
    return 'IMPOSSIBLE'


for tt in range(1,T+1):
    ans = '*'
    l = int(input())
    s = input()
    if l < 5:
        print("Case #"+str(tt)+": "+'POSSIBLE')
        continue
    state = [False for x in range(1<<5)]
    dfs(s, 0, 0, state)
    res = findPossible(s, 5, state)

    print("Case #"+str(tt)+": "+res)

   

