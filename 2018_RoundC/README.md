planetDistance.py: we apply the algorithm to find cycle in undirected graph.

fairiesAndWitches.cpp: Use binary number to document the state of node. For each state, every node must be used, which means we can only have even number of nodes. I used the popcount to precheck if the number of 1s in state is odd. If the number is odd, we ignore that state. For each state, we run dfs to pair up the nodes and form edges.
