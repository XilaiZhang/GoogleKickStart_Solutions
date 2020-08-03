monsterPath.py: dfs works, note that the first grid does not count.

safeSquares.cpp: dp. The max side length of safesquare is denoted as maxL\[i]\[j]. It can be computed from maxL\[i-1]\[j],maxL\[i]\[j-1] and maxL\[i-1]\[j-1].

evaluation.py: topological sort. Note that the base case comes from any name whose parent is '' (the empty char). For example, in a valid expression a=f(), the name a has a single parent ''. On the other a=f(b) where b is not defined, is not a valid assignment.
