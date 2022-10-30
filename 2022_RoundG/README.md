1. Walktober.py: compare with the max value for each day and sum up the differences. <br /><br />
2. Curling.py: sort all stones based on distance and calculate scores for the ones in the circle.<br /><br />
3. happySubarrays.py: The result can be computed through a math formula, and the math formula can be derived following the steps mentioned in offical analysis. What wasn't described in the offical analysis was how to compute the nearest smaller value, i.e., the nearest boundary index j to the right of index i, where prefix_sum[j] > prefix_sum[i -1]. To do so, we maintain a stack of indices, each index i in the stack corresponds to the prefix sum of index i. Now, as we move from left to right to iterate through the prefix sum array, we look at the current index. While the prefix_sum of current index is smaller than the prefix sum of the top index of the stack, we pop off the top index of the stack T_index, and record the nearest boundary index of the top index T_index to be current index. After the poppings are done, we also add the current index to the stack of indices. Note that the prefix sums of the stack of indices we maintain will be monotonically increasing. Eventually we plug in the boundary indices into the math formula to obatin the final result. <br /><br />
4. cuteLittleButterfly.cpp: This is an implementation of the NlogN solution as described for test set 3 in official analaysis, even though it does not pass the time limit of set 3. To pass set 3 we need to use segement trees like other solutions. Here I will just provide the implementation as aligning with the official analysis. We process the points based on their level of heights, from top to bottom. At each level, we keep two sets, each set is a collection of x coordinates. The first set records the max energy that can be obtained after visiting a point with position x from the left,  and the second set records the max energy that can be obtained after visiting a point with position x from the right. When considering each point, it can only be visited from a point that is of a higher level, which is the order of how we process the points. If the current point is visited from the left, then we can binary search on the first set to find the ancestor point on the left of current point with the max energy. Once we do so, we add the energy obtained from visiting current point to the first set as well. While inserting the current point to the set, we clean up and remove all the points that are to the right of the current point but with a smaller max energy. Cleaning up ensures that the points in our set are always in monotonically increasing order of max energy with respect to x coordinate, which is the pre-requisite of using a binary search approach. We maintain the second set using a similar way, but iterate from right to left. As we maintain and update the sets on each leavel, the time complexity is logN, and to iterate for all levels the overall time complexity is NlogN. 

<br /><br /><br /><br />**disclaimer: to increase chances of showing up on google search results, I will copy paste the problems spec below.** <br /><br />



```diff
Problem

John participates in an annual walking competition called Walktober. The competition runs for a total of N days and tracks the daily steps of the participants for all the N days. Each participant will be assigned a unique ID ranging from 1 to M where M is the total number of registered participants. A global scoreboard is maintained tracking the daily steps of each participant.

John is determined to win Walktober this year and his goal is to score the maximum daily steps on each of the N days among all the participants. Having participated in Walktober last year as well, he wanted to know how many steps he fell short of in achieving his goal. Given the previous year scoreboard, calculate the minimum additional steps he needed over his last year score in order to achieve his goal of scoring the maximum daily steps every day.

2022 is a year of the Winter Olympics! Curling has been one of the most popular winter sports as it requires skill, strategy, and sometimes a bit of luck.

In a curling game, two teams compete by sliding heavy granite stones on a long ice sheet. We call the teams the red team and the yellow team, as their stones are usually distinguished by the red and the yellow handle color. A curling game consists of several ends (subgames); in every end, the teams, each owning 8 stones, take turns to slide them across the long ice sheet toward a circular target area called the house. A stone may hit existing stones to change its own moving direction and other stones' position (including knocking them out of play). Roughly speaking, the goal for a team is to make their stones as close to the center of the house as possible.

Geometrically, a house and a stone can be modeled as a circle and a disk (the region bounded by a circle), respectively, and the scoring rules at the conclusion of each end are formally summarized as follows.

Each stone can be viewed as a disk of radius Rs on a 2-dimensional plane.
The house is a circle of radius Rh centered at (0,0).
Only stones in the house are considered in the scoring. A stone is in the house if any portion of the stone lies on or within the circle representing the house. Tangency also counts.
A team is awarded 1 point for each of their own stones in the house such that no opponent's stone is closer (in Euclidean distance) to the center than it. We assume in this problem that no two stones are equally close to the center (0,0).
Two teams are playing and have just delivered all their stones. The red team has N stones remaining on the curling sheet, centered at (X1,Y1),(X2,Y2),…,(XN,YN), while the yellow team has M stones remaining, centered at (Z1,W1),(Z2,W2),…,(ZM,WM). Now you are asked to figure out the scores of both teams.

Let us define F(B,L,R) as the sum of a subarray of an array B bounded by indices L and R (both inclusive). Formally, F(B,L,R)=BL+BL+1+⋯+BR.

An array C of length K is called a happy array if all the prefix sums of C are non-negative. Formally, the terms F(C,1,1),F(C,1,2),…,F(C,1,K) are all non-negative.

Given an array A of N integers, find the result of adding the sums of all the happy subarrays in the array A.

In a forest of the magical world, there lies a garden full of magical creatures. The garden has plenty of flowers which are not just beautiful but also a source of energy for butterflies.

Consider the garden a 2D plane where the X-axis represents the ground, and the Y-axis represents the altitude. There are plants of infinite height on every non-negative integral point on the X-axis. There are N flowers in the garden, where the i-th flower is on the point (Xi, Yi) with the nectar of some energy value Ci.

Our cute little butterfly wants as much energy as possible to become strong. By going to the same position of a flower, the butterfly can consume its nectar and gain that flower's energy value. Each flower's nectar can only be consumed once.

The butterfly is initially at point (0,1018) with 0 units of energy and facing towards the right. At any point, the butterfly can:

Move to a lower altitude, that is, from (x,y) to (x,y−1) only if its current altitude is positive (y>0).
Move in the positive direction along the X-axis, that is, from (x,y) to (x+1,y) if it is facing right.
Move in the negative direction along the X-axis, that is, from (x,y) to (x−1,y) if it is facing left.
Change the direction it is facing (from left to right or vice versa). This will consume E units of energy.
We know our butterfly is lazy, and it hates to move upwards during the journey. So, for this problem, we will assume that going upwards is not allowed. Also, energy can be negative at any point. Negative energy means the butterfly has spent more energy than it obtained from the flowers.

Find the maximum energy our cute butterfly can achieve.
```
