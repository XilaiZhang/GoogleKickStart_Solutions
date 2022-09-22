(I named my variables more verbosely now to increase readability)

1. sortTheFabrics.py: sort two arrays based on two criteria, and count the ones in the same positions. <br /><br />
2. waterContainerSystem.py: key is to find out how many containers are at each level, which can be done through bfs or dfs. binary search afterwards to find the maximum level of water. <br /><br />
3. storyOfSeasons.py: iterate backwards from the end day, and add in the seed when growth day of the seed is equal to the day from current day to end day. maintain the currently available seeds in a heap, which is sorted by the profit of the seeds. For example, in the example given:<br />
day 5: <br />
day 4: <br />
day 3: (1) add spinach and cabbage to heap  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     for all crops that started in heap from day 4 and after, calculate the max profit <br />
day 2: (2) add pumpkin to heap &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     for all crops that started in heap from day 3 and after, calculate the max profit <br />
day 1: (3) add carrots to profit heap &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  for all crops that started in heap from day 2 and after, calculate the max profit <br />
<br />
we will consider the days 3,2 and 1, because they corresponds to the days when a certain kind of seed becomes available (lets call them cutoff days). at each of these days, we consider the interval of one day before the current cutoff day, to the previous cutoff day. <br /><br /><br />
4. SchedullingOfAMeeting.cpp: first of all we sort all the meetings as events. If a meeting starts at time L, and ends at time R, then it would block any meeting with a length X that starts after L-X+1, and starts before R. for each person's meeting P, L, R, we create an event of meeting begin at time L-X+1, and create an event of meeting ends at time R. As we move along the time axis to put a meeting of length X, we process the current begin and end events at time T. <br /><br />
we maintain two multiset. multiset 1 keeps track of the top K tech lead with the smallest number of meetings, and multiset 2 keeps track of the other tech leads with bigger number of meetings. <br /><br />
for each time T, repeat the following steps: <br />
i. if it is a begin event, increment the tech lead's meeting count by 1. If it is an end event, decrement the tech lead's meeting count by 1. <br />
ii. erase the tech lead's old meeting count from the multiset, and insert the tech lead's new meeting count into the multiset.<br />
iii. after insertion, rebalance the two multisets by comparing the biggest element of multiset 1 with the smallest element of multiset 2. We only need to balance the multisets once because there is at most one element that is out of sync. <br />
iv. the current sum of multiset 1 would be a potential candidate of the result. <br />

repeat steps i to iv for all the time T, and take the smallest among them as the result.
                       
