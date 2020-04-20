import fileinput
from collections import Counter

lines=[]
for line in fileinput.input():
    lines.append(line.rstrip())

seq=1
caseNum=1

def parse(command):
	stack=[]
	times=1
	currentDict=Counter()
	for i in range(len(command)):
		if command[i].isalpha():
			currentDict[command[i]]+=1
		elif command[i].isdigit():
			stack.append(currentDict)
			currentDict=Counter()
			stack.append(command[i])
		elif command[i]=="(":
			stack.append(currentDict)
			stack.append("(")
			currentDict=Counter()
		elif command[i]==")":
			 
			while stack and stack[-1]!="(":
				prev=stack.pop()
				if type(prev) is str:
					for key in currentDict:
						currentDict[key]=currentDict[key]*int(prev)
				else:
					for key in prev:
						currentDict[key]=currentDict[key]+prev[key]
			stack.pop()#pop the matching (
			
			while stack and stack[-1]!="(":
				prev=stack.pop()
				if type(prev) is str:
					for key in currentDict:
						currentDict[key]=currentDict[key]*int(prev)
				else:
					for key in prev:
						currentDict[key]=currentDict[key]+prev[key]

			stack.append(currentDict)
			currentDict=Counter()
		i+=1
	if currentDict:
		while stack:
			prev=stack.pop()
			if type(prev) is str:
				for key in currentDict:
					currentDict[key]=currentDict[key]*int(prev)
			else:
				for key in prev:
					currentDict[key]=currentDict[key]+prev[key]
		return currentDict
	return stack[0]


while seq<len(lines):
	command=lines[seq]
	vals=parse(command)
	#print vals

	h=(vals["S"]-vals["N"])%(10**9)
	h=h+1
	w=(vals["E"]-vals["W"])%(10**9)
	w=w+1
	print "Case #"+str(caseNum)+": "+str(w)+" "+str(h)
	caseNum+=1
	seq+=1






