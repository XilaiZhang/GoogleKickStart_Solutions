K_goodness.py: In a single iteration, compare head and tail.
LshapedPlots.py: dp in 4 directions.
rabbitHouse.py: similar to trapping rain water(a leetcode problem), use heap.

Checksum.py: The key is to convert the original problem into a graph problem: graph nodes are row numbers and column numbers, edges XY in the new graph are coordinates (x,y) in the original grid where grid\[x]\[y]=-1. Afterwards, we calulate the maximum spanning forest using prim's algorithm: 1. when there is no cluster, pick a random vertex and create a cluster to start with. 2. When there is a cluster under consideration, we keep track of the cut edges between current cluster and outside cluster, and always pick the max cut edge. If we keep trak of the cut edges, the overall complexity is reduced to O(N^2).

Note: all questions in this round can be safely passed using pypy2. In general pypy is slower than C++.
