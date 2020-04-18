import fileinput
import sys

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

seq=1
caseNum=1
while seq<len(lines):
	N,K=lines[seq].split()
	N=int(N)
	K=int(K)
	intervals=[]
	times=lines[seq+1].split()
	high=0
	for t in range(1,len(times)):
		intervals.append(int(times[t])-int(times[t-1]))
		high=max(high,intervals[-1])
	low=1
	while low<high:
		#print str(low)+" "+str(high)
		mid=low+(high-low)/2
		count=0
		for interval in intervals:
			count+=interval/mid
			if interval%mid==0:
				count-=1
		if count>K:
			low=mid+1
		else:
			high=mid

	#print low
	print "Case #"+str(caseNum)+": "+str(low)
	caseNum+=1

	seq+=2
