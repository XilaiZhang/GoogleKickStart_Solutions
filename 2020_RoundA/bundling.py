import fileinput
from collections import defaultdict

class node(object):
	def __init__(self):
		self.count=1
		self.children=defaultdict(node)

def countTimes(dummy,K):
	count=0
	for child in dummy.children.values():
		count+=child.count/K
		count+=countTimes(child,K)
	return count

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

seq=1
caseNum=1
while seq<len(lines):
	N,K=lines[seq].split()
	N=int(N)
	K=int(K)
	dummy=node()
	for t in range(seq+1,seq+N+1):
		word=lines[t]
		it=dummy
		for c in word:
			if c in it.children:
				it.children[c].count+=1
			it=it.children[c]
	result=0
	q=[]
	for child in dummy.children.values():
		q.append(child)
	while q:
		current=q.pop()
		result+=current.count/K
		for child in current.children.values():
			q.append(child)
	print "Case #"+str(caseNum)+": "+str(result)
	caseNum+=1
	seq+=N+1
