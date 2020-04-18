import fileinput

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

i=1
seq=1
while i<len(lines):
	N,K,target=lines[i].split()
	N,K,target=int(N),int(K),int(target)
	stacks=[]
	for j in range(i+1,i+N+1):
		line=lines[j].split()
		other=[0]
		for l in line:
			other.append(other[-1]+int(l))
		stacks.append(other)	
	dp=[[0 for y in range(target+1)] for x in range(N+1)]

	

	for q in range(1,N+1):
		for t in range(target+1):
			for currentNum in range(min(t+1,K+1)):
				#if dp[q-1][t-currentNum]:
				dp[q][t]=max(dp[q][t],stacks[q-1][currentNum]+dp[q-1][t-currentNum])
	
	print dp
	print "Case #"+str(seq)+": "+str(dp[N][target])
	i+=N+1
	seq+=1
