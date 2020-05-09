from collections import defaultdict,deque


class node(object):
    def __init__(self):
        self.children=defaultdict(node)
        self.depth=0
        self.end=False

class solution(object):
    def helper(self,dummy,N):
        count=0
        if dummy.end:
            count+=2**(N-dummy.depth)
        else:
            for key in dummy.children:
                count+=self.helper(dummy.children[key],N)
        return count
    
    def solve(self):
        T=raw_input()
        T=int(T)
        for tt in range(1,T+1):
            N,Q=raw_input().split()
            N,Q=int(N),int(Q)
            dummy=node()
            for i in range(Q):
                it=dummy
                depth=0
                for c in raw_input():
                    it=it.children[c]
                    depth+=1
                    it.depth=depth
                    if it.end:
                        break
                it.end=True
            bad=self.helper(dummy,N)
            result=2**N-bad
            print "Case #"+str(tt)+": "+str(result)

if __name__=="__main__":
    s=solution()
    s.solve()
    


    

        
        

