DogsAndCats: simulation of the process. <br />
<br />
StayingHyradted: First of all similar to previous google problems, we break the problem into two separate problems, one along the x - axis, and the other along the y - axis. Along each axis, we try to find the balancing point, and that point should always happen on a start event or an end event of a rectangle. (for example, a rectangle ranging from 2 to 4 along one side has a start event at 2, and an end event at 4). We can either find this point by binary search or simple iteration, since the overall time complexity is bounded by sorting, which costs N log N. <br />
<br />
BananaBunches: Suppose we have two segments L1 and L2, Where L1 + L2 has a total length of N. As we iterate from left to right, and as the size of L1 is growing, we want to know: in L2, what is the minimum length to create a sum S. But if we move from left to right, then L2 is becoming smaller and smaller, and we do not have a convenient way to maintain all the optimal sums. On the other hand, if we move from right to left, we can keep track of all the optimal sums that are in L2, and add more sums to it as we iterate. In summary, we move from right to left, building possible sums in L1 starting from current index, and also use information of the optimal sums that has been building up in L2. <br />
<br />
simplePolygon: Pick's theorem was my favorite grid formula back in high school. I haven't used it for decade since high school and am thrilled to see it again today. 
<br />
