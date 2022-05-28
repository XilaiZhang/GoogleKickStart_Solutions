from curses.ascii import isalnum


T=int(input())

for tt in range(1,T+1):
    N = int(input())
    password = input()
    hasUpper = False
    hasLower = False
    hasDigit = False
    hasSpecial = False
    for char in password:
        if char.isalpha() and char.islower():
            hasLower = True
        if char.isalpha() and char.isupper():
            hasUpper = True
        if char.isdigit():
            hasDigit = True
        if char in '#@*&':
            hasSpecial = True
    if not hasUpper:
        password += 'A'
    if not hasLower:
        password += 'a'
    if not hasDigit:
        password += '0'
    if not hasSpecial:
        password += '@'
    if len(password) < 7:
        password += 'a' * ( 7- len(password))
    print("Case #"+str(tt)+": "+password)
    

