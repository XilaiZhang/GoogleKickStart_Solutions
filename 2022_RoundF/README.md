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
                       
                       
                       
<br /><br /><br /><br />**disclaimer: to increase chances of showing up on google search results, I will copy paste the problems spec below.** <br /><br />



```diff
Problem
A fabric is represented by three properties:

Color (C), a string consisting of lowercase letters of the English alphabet, representing the color of the fabric.
Durability (D), an integer representing the durability of the fabric.
Unique identifier (U), an integer representing the ID of the fabric.
Ada and Charles work at the Kick Start fabric factory. Each day they receive N fabrics, and one of them has to sort it. They sort it using the following criteria:

Ada sorts in lexicographically increasing order by color (C).
Charles sorts in ascending order by durability (D).
They break ties by sorting in ascending order by the unique identifier (U).
Given N fabrics, count the number of fabrics which end up in the same position regardless of whether Ada or Charles sort them.
Problem
There is a water container system with N identical containers, which can be represented as a tree, where each container is a vertex. The containers are connected to each other with N−1 bidirectional pipes. Two containers connected to each other are always placed on adjacent levels. Formally, if two containers a and b are connected to each other, then |levela−levelb|=1. Container 1 is placed at the bottommost level. Each container is connected to exactly one container on the level below (the only exception is container 1, which has no connections below it), but can be connected to zero or more containers on the level above. The maximum capacity of each container is 1 liter, and initially all the containers are empty. Assume that the pipe has a capacity of 0 liters. In other words, they do not store any water, but only allow water to pass through them in any direction.

Consider the following diagram which is an example of a water container system:

Image of the water container system for the problem statement

The first level of the system consists of a single container, container 1 (root). Container 1 is connected to container 2 and container 3, which are present in the above level, level 2. Container 2 is also connected to container 4, which is present at level 3.

You are given Q queries. Each query contains a single integer i which represents a container. For each query, add an additional 1 liter of water in container i.

The following diagram illustrates the flow of the water in the system in different conditions:

Image describing the flow of water in the water container system

In step 1, after adding 1 liter of water in container 3, the water flows downward because the water containers at the lower level are still empty.
In step 2, after adding 1 liter of water in container 3, the water flows downward, but as the container 1 is already filled completely, the water is distributed evenly between water containers 2 and 3.
In step 3, after adding 1 liter of water in container 3, the water containers 2 and 3 are completely filled.
In step 4, after adding 1 liter of water in container 3, the water is pushed up to water container 4, which is then completely filled.
As illustrated in the example above, containers at the same level will have the same amount of water. Find the number of water containers that are completely filled after processing all the queries.
You are a super farmer with some vegetable seeds and an infinitely large farm. In fact, not only are you a farmer, but you are also secretly a super programmer! As a super programmer, you hope to maximize the profit of your farming using your programming skills.

Since your daily energy is limited, you can plant at most X seeds each day. In the beginning, you have N kinds of vegetable seeds. The number of seeds of the i-th kind of vegetable is Qi, and each seed of this kind needs Li days to mature from the day it is planted. Once it matures, you can sell it for Vi dollars. Assume that no energy or time is required for harvesting and selling vegetables. Also, your farm is infinitely large so the growing vegetables do not crowd out each other.

Notice that although the area of your farm is infinite, the number of days that you can plant seeds is limited. The warm season only lasts D days, and after that, the harsh winter comes. Any vegetable that has not matured yet will die immediately and cannot be turned into profit. The remaining seeds that were not planted cannot be turned into profit either.

As a super farmer and a super programmer, you want to come up with a perfect planting plan that will maximize your profit. Find the total amount of profit you will earn.
Scheduling meetings at Google is not an easy task. Even with the help of Google Calendar, Ada has a lot of difficulty with it!

Ada works as a Software Engineer at Google, and needs to get approval for her new project. In order to get an approval, she needs to meet with at least K of N Tech Leads.

Ada has access to the calendars of all N Tech Leads. For each Tech Lead, Ada can see all their scheduled meetings. The timeline in this problem can be viewed as D consecutive hours, and all meetings are in [0,D] hours range, with both ends being integer numbers. Scheduled meetings, even for the same person, can overlap (people are notorious for this at Google!).

Ada needs to schedule an X-hour-long meeting in the interval of [0,D] hours, with both ends being integer numbers as well. At least K of N Tech Leads should be present for the whole meeting, that is their calendar should be completely free for the entire meeting duration.

Unfortunately, it might be the case that it is already impossible to find a slot to schedule such an X-hour-long meeting. In that case, Ada will need to persuade some Tech Leads to cancel their existing meetings.

What is the minimum number of scheduled meetings that need to be canceled so that Ada can meet with at least K Tech Leads?




```
