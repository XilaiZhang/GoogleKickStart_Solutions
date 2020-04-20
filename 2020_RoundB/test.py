import fileinput
from collections import defaultdict

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

seq=1
caseNum=1

while seq<len(lines):
	numbers=lines[seq].split()
	total=0
	digitSum=0
	for i in range(1,len(numbers)):
		num=int(numbers[i])
		total+=num
		digitSum+=num*i
	digitSum%=11
	if digitSum%2==1:
		digitSum=(digitSum+11)/2
	else:
		digitSum=digitSum/2
	dp=[[[0 for z in range(11)]for y in range(total/2+1)] for x in range(10)]
	for t in range(numbers[0]):
		dp[1][t][t]=1
	for x in range(2,10):
		for y in range(total/2+1):
			for z in range(11):
				for count in range(numbers[x]):
					currentMod=(count*x)%11
					if dp[x-1][y-count][(z-currentMod)%11]==1:
						dp[x][y][z]=1
						break


	print "Case #"+str(caseNum)+": "+str(dp[9][total/2][])
	caseNum+=1
	seq+=1