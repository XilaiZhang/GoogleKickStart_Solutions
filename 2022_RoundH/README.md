The below analysis is an extension / correction based on official analysis. You can click on "analysis" to view offical analysis first. 

1. RunningInCircles.py:  We keep track of a few things: the direction when we last passed the starting line, the direction of the last run just before taking the break, and the offset of the current position relative to the starting line based on current direction. With these three variables being maintained, we can code up the different scenarios described in the spec using `if` and `else` statements. <br /><br />
2. MagicWellOfLilles.py: To reach any coin amount i, the last step to reach i is either a 1 coin operation, or a 2 coin operation, since it is stupid to end the operations with a 4 coin operation. And if we ended with a 2 coin operation, then we can assume the 2 coin operation is preceded by a number of other 2 coin operations before it, and stopped upon seeing a 4 coin operation. This is because a 1 coin operation preceding a 2 coin opeartion can always be shifted to be a 1 coin operation after a 2 coin operation. To compute along the way of 4 coin and 2 coin operations, we need to find the divisors of the current coins. (For example, dp[i] is the value of current coins, then dp[j] which ended at a 4 coin opeartion, must obey that dp[j] is a divisor of dp[i]) Finally, we populate the dp table by multiplying the divisor from divisor being in the range [1,n], as opposed to populating the dp table by checking the divisors of the current coin sum. <br /><br />
3. Electricity.py: the max flow of a point i, dp[i], is the sum of dp[j] of all j which are neighbors of i and are smaller than i, plus 1 (i itself). i.e., dp[i] = sum(dp[j])+1 where j is a neighbor of i and smaller than i. <br /><br />
4. LevelDesign.cpp: As of 11/15/2022, the sample code probided by the official solution is **wrong**. <br />
When trying to pop out indices that require more swaps from the deque, the line in official analysis wrote <br />
```
while(!dq.empty() and dp[i - 1][l] <= dp[i - 1][dq.back()]) {
```
However, this check did not take into considerations of the extra number of cycles needed, had we picked a smaller index. For example, suppose the back of deque is a smaller index 0, and our current index is a bigger index 20, and we are comparing the two indices. Suppose the current cycle size is 5. Now, if we simply compare between dp[i-1][0] and dp[i-1][20], then we are failing to take into considerations that, between the diff of index 0 of 20, there are a length of 20, which would require an extra 20 / 5 = 4 number of operations. This extra number of cycles should have been calculated as `(diff between indices) / (cycle size)`. In other words, the line in official analysis would only be correct if we change it to be
```
while(!dq.empty() and dp[i - 1][l] <= dp[i - 1][dq.back()] + (l - dq.back()) / cs) {
```
I have proved this by submitting answers with and without this extra compensation term. In my solution that passes both test cases, I explicitly named this extra term which should be added on top of the smaller index `compensation`. <br /><br />
Besides that, we perform a semi-(minimum range query) using deque on top of dynamic programming to compute the answer, which aligns with the rest of the offical analysis. 

<br /><br /><br /><br />**disclaimer: to increase chances of showing up on google search results, I will copy paste the problems spec below.** <br /><br />



```diff
Problem
A permutation cycle in a permutation C is a sequence of integers (a1,a2,…,ak) such that the following hold:

ai∈C for all i, and are distinct.
For each i∈{1,2,…,k−1}: C[ai]=ai+1, and C[ak]=a1.
A permutation cycle of length k is called a k-cycle.

For example, the permutation C=[4,2,1,3] has two cycles: the 3-cycle (4,3,1), and the 1-cycle (2). (4,3,1) is a cycle because C[4]=3, C[3]=1, and C[1]=4.

Sample case.

Grace loves permutation cycles, so Charles decides to design an N-level game to challenge her.

At the start of the game, the player is given an N-length permutation P of integers from 1 through N. The levels in the game are numbered from 1 to N. At each level, the player starts with the given permutation, and is allowed to make modifications to it by swapping any two elements in it (multiple swaps allowed). To clear the k-th level in the game, the player is required to find the minimum number of swaps using which a k-cycle can be created in the permutation. The player can progress to the (k+1)-th level only after clearing the k-th level.

Grace finds the game a bit challenging, but wants to win at any cost. She needs your help! Formally, for each level k, you need to find the minimum number of swaps using which a k-cycle can be created in the permutation.

Ben works as an engineer in a city with N electric junctions. These junctions form a network and can be visualised as a connected graph with N vertices and N−1 edges. The city is facing a power outage, due to which none of the junctions are receiving electricity, and Ben is in charge of handling the situation.

Each junction has a fixed electric capacity. Ai is the electric capacity of the i-th junction. Due to resource constraints, Ben can provide electricity to only one junction, but other junctions can receive electricity depending on their connections and capacities. If the i-th junction receives electricity, then it will also get transmitted to all the junctions directly connected to the i-th junction whose capacity is strictly less than Ai. Transmission stops if no eligible junction is present. Help Ben determine the maximum number of junctions that can receive electricity.
There is a deep magical well in a forest that has some lilies on its waters. You have a large empty basket and some coins, and are standing next to the well. You have more coins than there are lilies in the well. The well has taken note of the fact that your basket is empty.

If you toss one coin into the well, the well will toss out one lily into your basket. If you toss four coins at once into the well, the well will take note of how many lilies it has tossed out into your basket so far. If you toss two coins at once into the well, the well will toss out as many lilies into your basket as it had last taken note of. If you toss one coin, or two coins at once, into the well, and there are not enough lilies left in the well, the well will not toss out any lilies.

Given the number of lilies L in the well at the beginning, return the minimum number of coins you will need to toss into the well to make it toss all of its lilies into your basket.

Ada has decided that this year, she will take part in the annual marathon that takes place in her city. Since this is the first time she would be running such a long distance, she has decided to start practising for it by running in the circular track of length L units near her house.

Ada wants to focus only on running, so she decides to use a machine to count the number of laps she has run. The machine is placed at the starting line of the circular track and starts the count from 0. Every time Ada arrives at the starting line running in the same direction as the last time she departed from the starting line, the machine increases the number of laps that Ada has run by 1. If she crosses the starting line or changes direction at the starting line, the machine considers the new direction as the direction she last touched the starting line. The machine only remembers the last direction in which Ada touched the starting line. During a lap, Ada can change directions any number of times, but as long as she eventually touches the starting line in the same direction as she last touched it, the count of laps in the machine increases by 1.

This is the first time Ada has practised running long distances, so she cannot run continuously. She runs some distance, then takes a break to regain her energy. However, when she starts running again after taking a break, she cannot remember which direction she was running in previously. So she picks one of the directions, clockwise or anticlockwise, and starts running from the same position where she stopped.

Ada begins at the starting line and is initially facing in the direction of her first run. She runs a total of N times, taking breaks in between. Given the information of the distance Di units Ada has run, and the direction Ci she has taken (clockwise or anticlockwise) when she ran the i-th time, for all i from 1,…,N, can you tell the number of laps that would be reported by the machine at the end?
```
