1. ColoringGame.py: robot would score 1 point for every 5 blocks from the left. <br />
2. StudentsAndMentors.cpp: suppose current student score is S, binary search on the sorted student scores, and find the first score smaller than or equal to 2 times the current score, call it S_target. If S_target equals to S, without loss of generality, we assume it is the same student, and look at the student 1 spot to the left instead. Return if there is a different student other than self that qualifies. <br />
3. MatchingPalindrome.py: Math proof is detailed in official analysis. Essentially, keep reducing the palidrome by mirroring the smaller part of the palindrome from tail to head (or from head to tail). The conclusion from repeated reduction is that, the length of Q must divide N. <br />
4. PizzaDelivery.cpp: Use the dp relation detailed in official analysis. Here are some caveats in implementation: <br />
i. the direction is oriented as north, east, west, south. Not clockwise or counter clockwise. <br />
ii. Keep in mind the potential of overflow. If your default value for dp is huge, skip operation on the default value. <br />
iii. Don't forget the case where the person does not move. <br />
iv. Only propagate the dp relationship if the previous state is reachable. If the previous states is not reachable, do not propagate the dp relation. <br >


<br /><br /><br /><br />**disclaimer: to increase chances of showing up on google search results, I will copy paste the problems spec below.** <br /><br />



```diff
Problem
Ada delivers pizzas in a city consisting of a grid of N horizontal and N vertical streets, heading from North to South and from West to East, respectively, and numbered from 1 to N. The top left street crossing of the grid is (1,1).

Today, Ada has to deliver P pizzas, one for each of P customers. Each customer lives at a different street crossing; the k-th customer lives at street crossing (Xk,Yk) and will pay Ada Ck coins after the pizza is delivered to their location.

Ada starts at her pizza restaurant at (Ar,Ac) with 0 coins and carrying P pizzas. Her goal is to deliver all of the pizzas within M minutes. She is free to take any path she likes around the city and finish deliveries anywhere, as long as she manages to drop off all P pizzas to their respective customers within M minutes. It takes one minute to walk between two adjacent street crossings, and takes no additional time to drop off a pizza at a customer's location. There are some additional rules and constraints to note:

You are given a palindrome string P of length N consisting of only lowercase letters of the English alphabet. Find the shortest non-empty palindrome string Q such that P concatenated with Q forms a palindrome. Formally, the string PQ forms a palindrome.

A group of N students prepares together for upcoming programming competitions such as Kick Start and Code Jam by Google. To help each other prepare, it was decided that each student will pick a mentor among other students. A mentor will help their mentee to solve problems, learn algorithms, track their progress, and will generally support them throughout preparation.

Each student will have exactly one mentor among all other students, and a person can be a mentor to multiple people. For every student i we know their rating Ri which approximates how good that student is at programming competitions. Because it is believed that a mentor should not be much stronger than their mentee, a student j can be a mentor of student i only if Rj≤2×Ri. Note that a mentor can even have a rating that is lower or equal to their mentee's rating.

Unsurprisingly, each student wants to have the strongest possible mentor. For each student, can you help to figure out what is the highest possible rating of a mentor they can pick?

John loves to play computer games. He recently discovered an interesting game. In the game there are N cells, which are aligned in a row from left to right and are numbered with consecutive integers starting from 1. Initially, all cells are coloured white. A cell is valid if it has white color and it does not have any adjacent red colored cell. On each turn, a player paints any valid cell with the red color. The game ends when no valid cells are present. The score of the player is equal to the number of cells they paint.

To master the game, John is practicing against a bot. The bot is poorly trained and it always paints the first valid cell from the left. John on the other hand is playing the game very carefully and he can choose any valid cell. The bot makes the first move and the players take turns alternately.

Find the maximum achievable score by the bot, assuming that John is playing optimally to minimize the score of his opponent.


```
