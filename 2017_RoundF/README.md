cake.cpp: Note that we can check if a number is a perfect square by taking the squre root, and check if sqrt(x)-floor(sqrt(x))==0. 

kickSort.cpp: My implementation is N log N time complexity. The offical analysis proposed a O(N) solution by making a key observation: in the worst case, we will always select indexes in the following pattern: one to the right, two to the left, three to the right.... e.g. if we have 6 elements, we will select in the following order: 2,3,1,4,0,5.
