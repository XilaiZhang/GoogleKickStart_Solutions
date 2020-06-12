T=raw_input()
T=int(T)

for tt in range(1,T+1):
    word=raw_input()
    result=""
    if len(word)%2==0:
        answer=["A" for x in range(len(word))]
        for i in range(1,len(word),2):
            if i==1:
                answer[1]=word[0]
            else:
                raw=(ord(word[i-1])-65)-(ord(answer[i-2])-65)
                if raw<0:
                    raw+=26
                answer[i]=chr(raw+65)

        for i in range(len(word)-2,-1,-2):
            if i==len(word)-2:
                answer[i]=word[-1]
            else:
                raw=(ord(word[i+1])-65)-(ord(answer[i+2])-65)
                if raw<0:
                    raw+=26
                answer[i]=chr(raw+65)
        result="".join(answer)
    else:
        result="AMBIGUOUS"

    print "Case #"+str(tt)+": "+str(result)

    
        

