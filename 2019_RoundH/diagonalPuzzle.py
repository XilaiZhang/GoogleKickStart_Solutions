import fileinput
from collections import defaultdict

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

def helper(start,val,neighbor,joint):
	flip=defaultdict()
	flip[start]=val
	flipCount=0
	if val:
		flipCount+=1
	q=[start]
	while q:
		number=q.pop()
		for j in neighbor[number]:
			if j not in flip:
				if not flip[number]:
					if not joint[number,j]:
						flip[j]=1-flip[number]
					else:
						flip[j]=flip[number]
				else:
					if not joint[number,j]:
						flip[j]=1-flip[number]
					else:
						flip[j]=flip[number]
				if flip[j]:
					flipCount+=1
				q.append(j)
	return flipCount

seq=1
caseNum=1
result=0
while seq<len(lines):
	N=int(lines[seq])
	neighbor=defaultdict(list)
	joint=defaultdict()
	for x in range(N):
		for y in range(N):
			a=x+y
			b=y-x+3*N
			neighbor[a].append(b)
			neighbor[b].append(a)
			if lines[seq+1+x][y]==".":
				joint[a,b]=0
				joint[b,a]=0
			else:
				joint[a,b]=1
				joint[b,a]=1
	
	count1=helper(0,0,neighbor,joint)
	count2=helper(0,1,neighbor,joint)

	count3=helper(1,0,neighbor,joint)
	count4=helper(1,1,neighbor,joint)
	print str(count1)+" "+str(count2)+" "+str(count3)+" "+str(count4)
	result=min(count1,count2)+min(count3,count4)


	print "Case #"+str(caseNum)+": "+str(result)
	caseNum+=1
	seq+=N+1
