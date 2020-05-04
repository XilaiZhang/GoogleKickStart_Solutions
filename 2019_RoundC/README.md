wiggleWalk.py has the best time complexity you can achieve, strictly O(N).

My approach in circuitBoard.py: first use heap to record the maximum length of consecutive good cells starting from each position. After that we use the histogram approach (https://leetcode.com/problems/largest-rectangle-in-histogram/) to find max area. 

problem 3 is a knapsack problem. The thing to notice is that we cannot assume dog positions are given in ascending order, thus we need to sort!
