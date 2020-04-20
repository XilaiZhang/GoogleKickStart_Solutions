import fileinput

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

seq=1
caseNum=1

while seq<len(lines):
	numbers=lines[seq+1].split()
	for j in range(len(numbers)):
		numbers[j]=int(numbers[j])
	count=0
	#print numbers
	for i in range(1,len(numbers)-1):
		if numbers[i]>numbers[i-1] and numbers[i]>numbers[i+1]:
			count+=1


	print "Case #"+str(caseNum)+": "+str(count)
	caseNum+=1
	seq+=2