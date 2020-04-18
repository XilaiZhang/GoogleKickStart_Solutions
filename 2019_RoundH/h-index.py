import fileinput
import heapq

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

seq=1
caseNum=1
while seq<len(lines):
	N=int(lines[seq])
	indices=lines[seq+1].split()
	q=[]
	h=0
	result=""
	for index in indices:
		index=int(index)
		heapq.heappush(q,index)
		while q and q[0]<h+1:
			heapq.heappop(q)
		if len(q)>h and q[0]>h:
			h+=1
		#print q
		result+=" "+str(h)
	print "Case #"+str(caseNum)+":"+result
	caseNum+=1
	seq+=2