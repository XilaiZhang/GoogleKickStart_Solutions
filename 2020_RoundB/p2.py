import fileinput

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

seq=1
caseNum=1

while seq<len(lines):
	N,K=lines[seq].split()
	N=int(N)
	K=int(K)
	numbers=lines[seq+1].split()
	for j in range(len(numbers)):
		numbers[j]=int(numbers[j])
	boundary=K

	for t in range(N-1,-1,-1):
		boundary=boundary-boundary%numbers[t]


	print "Case #"+str(caseNum)+": "+str(boundary)
	caseNum+=1
	seq+=2