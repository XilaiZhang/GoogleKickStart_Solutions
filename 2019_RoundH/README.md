For the second problem, transform the graph into a 2 coloring problem.

For the third problem, if two numbers are greater or equal to 10, then the result is yes. Thus in the case of a single number being greater than 10, the maximum count of the rest of the numbers are 8\*9=72. The key observation is that if the number is greater than 72, then the part greater than 72 can be cancelled in pairs of 2. Taking in to consideration of parity, we can convert numbers greater than 72 to be either 72 or 73, which covers all values of difference between the odd and even groups.
