candies.cpp: the approach of sliding window + set/map was clear from the start. However, it took me infinite amount of time to debug that in c++, modolo of negative number could be a negative number! 

paraGliding.cpp: identify the critical towers that matters for each ballon. For implemenatation details, we use std::distance to process the returned type from lower_bound.

funniestWordSearch.cpp: The official analysis implies that you can't use the relationship of totals\[i1,j1,i2,j2] = S(i2, j2) - S(i1 - 1, j2) - S(i2, j1 - 1) + S(i1 - 1, j1 - 1) for large dataset. And I am here to prove that you can! My implementation passes large dataset smoothly. All you have to do is to document words that ends at position \[i,j] with lengths not greater than k. (I used a trie structure to save some time.)
