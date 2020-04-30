complexity analysis of problem 3:

The main complexity reduction comes from the elimination of preprocessing and precomputation. If we find the number of primes 
of every number in range R, we need R log log R complexity, which produces a magnitude of 10^9. However, if we calculate 
the count of prime numbers for each test case, we would need (R-L+1)* log log sqrt(R) for each test case. For all test cases,
we would need T* (R-L+1)* log log sqrt(R), which is of the magnitude 10^7. Thus the elimination of preprocessing would make
our code at least 100 times faster. 

A breif summary of our approach: we first spend sqrt(R) log log (sqrt(R)) complexity to find all primes numbers not 
greater than sqrt(R). After that, for each test case, we spend T* (R-L+1)* log log sqrt(R) to examine each number in the 
range(L,R) and check if the number is a multiple of a previously found prime number. Overall , the time complexity is 
approximately 10^7.
