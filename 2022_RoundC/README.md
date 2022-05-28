It's finally the long weekend, and I have the time to type up the solutions. <br /><br />

newPassword.py: straightforward implementation, can follow official analysis. <br /><br />
rangePartition.py: every sum in the range from 1 to sum(1...N) can be constructed. always start from the biggest number and construct backwards. <br /><br />
antsOnAStick.py: This is one of those Ah-Ha questions that amazes you. Key observation is that whenever two ants meet and bounce off each other, we can think of them as just running pass each other and changing name tag. We always know that ants on the tip of the sticks are going to fall off first, and therefore all we need to know is whether the leftmost ant fall off first, or the ant on the right most part fall off first. Turns out we can solve this by ranking the time of the fall off events. For any ant that is at postion X, (i) if it is moving towards the left, there will be a fall off event on the left tip at time X. (ii) if the ant is moving towards the right, there will be a fall off event on the right tip of the stick at time L-X. Now that we know when and where (either left tip or right tip) the ants fall off. We can construct the answer by stripping ants from the left and right sides. <br /><br />
PalindromicDeletions.py: First of all, as detailed in official analysis, we construct the expections by suming up K! * (L-K)! * (number of palindrome of length K), and dp(L,R,len) equals the number of palindromes of length len that can be found as a subsequence of the substring S\[L,R] (indices L and R inclusive). The way I implemented the dp relations are, we start from the first loop, which is the str_len, the length of range \[ L, R ] of input string S we are interested in. The second loop is the starting position of the range, and the third loop ranges over the variable len, which is the length of palindrome inside this range. <br />
different from what other people did, after we retrieved the raw result, I just applied fermat's little theorem to retrieve the eventual result. Using fermat's little theorem is fast and easy to implement, and all we need is a helper function on fast power. related article on fermat's little theorem https://www.geeksforgeeks.org/fermats-little-theorem/#:~:text=Fermat's%20little%20theorem%20states%20that,an%20integer%20multiple%20of%20p.&text=ap%20%E2%89%A1%20a%20(mod,an%20integer%20multiple%20of%20p. <br />

<br /><br />**disclaimer: to increase chances of showing up on google search results, I will copy paste the problems spec below.** <br /><br />



```diff
Problem
# A company named Gooli has issued a new policy that their employees account passwords must contain: 

# At least 7 characters.
# At least one uppercase English alphabet letter.
# At least one lowercase English alphabet letter.
# At least one digit.
# At least one special character. There are four special characters: #, @, *, and &.
# The company has asked all the employees to change their passwords if the above requirements are not satisfied. Charles, an employee at Gooli, really likes his old password. In case his old password does not satisfy the above requirements, Charles will fix it by appending letters, digits, and special characters. Can you help Charles to find the shortest possible new password that satisfies his company's requirements?

# Problem
# Alan and Barbara suddenly felt like playing with numbers. Alan chooses a non-empty subset from the set of first N positive integers (1,2,…,N). Barbara takes the rest of the numbers (if any) from the set. And then they both calculate the sum of the elements in their respective sets.

# Alan believes in a magic ratio, which is X:Y. Hence, Alan wants to choose the subset in such a way that the ratio between the sum of Alan's subset and the sum of Barbara's subset is exactly X:Y.

# Can you help Alan to choose a subset that can achieve the desired ratio?

# Problem
# Ada has N ants labelled from 1 to N. She decides to test John's concentration skills. She takes a stick L cm long, and drops the ants on it.

# The positions on the stick at which the ants are dropped are represented by an integer array P, where ant i is dropped at the position Pi (that is, Pi cm away from the left end) on the stick. Each ant travels either to the left or right with a constant speed of 1 cm per second. The initial directions of the ants is represented by an array D, where the direction of ant i is Di: 0 if left, and 1 if right. When two ants meet, they bounce off each other and reverse their directions. The ants fall off the stick when they reach either end of it.

# Ada challenges John to find the exact order in which the ants fall off the stick. John needs your help!

# Problem
# Games with words and strings are very popular lately. Now Edsger tries to create a similar new game of his own. Here is what he came up with so far.

# Edsger's new game is called Palindromic Deletions. As a player of this game, you are given a string of length N. Then you will perform the following process N times:

# Pick an index in the current string uniformly at random.
# Delete the character at that index. You will then end up with a new string with one fewer character.
# If the new string is a palindrome, you eat a piece of candy in celebration.
# Now Edsger wonders: given a starting string, what is the expected number of candies you will eat during the game?
```
