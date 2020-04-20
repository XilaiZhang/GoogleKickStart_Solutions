import fileinput
from collections import Counter

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

seq=1
caseNum=1

while seq<len(lines):
	W,H,L,U,R,D=lines[seq].split()
	W=int(W)
	H=int(H)
	L=int(L)
	U=int(U)
	R=int(R)
	D=int(D)

	dp=[0 for x in range(W+1)]


	for j in range(1,H+1):
		leftProb=0
		for i in range(1,W+1):
			if i==1 and j==1:
				dp[1]=1
				leftProb=1
				continue
			if L<=i<=R and U<=j<=D:
				dp[i]=-1
				leftProb=-1
				continue
			current=0
			if leftProb!=-1:
				if j==H:
					current+=leftProb
				else:
					current+=leftProb*0.5
			if dp[i]!=-1:
				if i==W:
					current+=dp[i]
				else:
					current+=dp[i]*0.5
			leftProb=current
			dp[i]=current
		#print dp
		
	#print dp

	print "Case #"+str(caseNum)+": "+str(dp[i])
	caseNum+=1
	seq+=1






