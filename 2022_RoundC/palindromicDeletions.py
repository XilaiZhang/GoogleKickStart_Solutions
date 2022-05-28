T=int(input())

mod = int(1e9+7)
dp = [[[0 for z in range(402)] for y in range(402)] for x in range(402)]

def power(x,y):
    if y == 0:
        return 1
    child_power = power(x, y >> 1)
    my_power = child_power * child_power % mod
    if (y & 1):
        my_power = my_power * x % mod
    return my_power % mod

def get_inv(x):
    return power(x, mod - 2)

fac = [1 for x in range(401)]
rev_fac = [400 for x in range(402)]
rev_fac[401] = 1
for i in range(1, 401):
    fac[i] = i * fac[i-1] % mod

for tt in range(1,T+1):
    N = int(input())
    S = input()


    for str_len in range(1, N+1):
        for start in range(0, N - str_len + 1):
            end = start + str_len - 1
            dp[start][end][0] = 1
            dp[start][end][1] = end - start + 1
            for len in range(2, str_len+1): # this len is length of palindrome
                dp[start][end][len] = 0
                dp[start][end][len] = (dp[start][end][len] + dp[start+1][end][len]) % mod 
                dp[start][end][len] = (dp[start][end][len] + dp[start][end-1][len]) % mod 
                dp[start][end][len] = (dp[start][end][len] - dp[start+1][end-1][len] + mod) % mod 
                if S[start] == S[end]:
                    if start == end - 1:
                        dp[start][end][len] =  (dp[start][end][len] + 1) % mod 
                    else:
                        dp[start][end][len] =  (dp[start][end][len] + dp[start+1][end-1][len-2]) % mod 

    result = 0
    for count in range(0, N): # the original string does not count according to the rules
        result = result + dp[0][N-1][count] % mod * fac[count] % mod * fac[N-count] % mod
    # lets just use fermat's little theorem instead of something fancy
    result = result * power(fac[N], mod - 2) % mod

    print("Case #"+str(tt)+": "+str(result))
