sightSeeing.cpp: dp\[i]\[j] is the earliest time to arrive at i after sightseeing j cities. I used long long for everything just to be safe. 

sherlockAndTheMatrixGame.cpp: This is a N^2 log K solution. The memory constraints do not allow a segment tree implementation. A worst case N^2 log range log N solution (uses multiset to generate the largest K prefix sums) passes the large dataset. Even though this implementation does not pass the large dataset, its worst case time complexity is better.
