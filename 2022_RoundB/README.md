during the round B weekend I participated in Code Jam instead, and qualified for round 2 with a top 1500.<br />

1.infinityArea : nit. can be solved following official solution.<br />
2.palindromicFactors : nit. can be solved following official solution.<br /><br />
3. unlockThePadlock: According to the spec, all rotations are strictly inclusive. (there can't be partially overlap rotation ranges). 
Suppose we do rotations from larger ranges to smaller ranges. Now, consider an outer rotation of the range \[A .... B\], there could only be 3 situations for the next inner rotation. <br />
&nbsp;&nbsp;&nbsp;&nbsp;i. the inner rotation is \[M .... N\], where M > A and N < B. In this case, the amount rotated is the same from both ends (considering either from A's end or from B's end)<br />
&nbsp;&nbsp;&nbsp;&nbsp;ii. the inner rotation is \[A .... N\], where N < B. In this case, the amount rotated in this cycle must be calculated from B's side.<br />
&nbsp;&nbsp;&nbsp;&nbsp;iii. the inner rotation is \[M .... B\], where M > A. In this case, the amount rotated in this cycle must be calculated from A's side.<br />
therefore, the dp transition from the outer range to the inner range can be achieved, either through rotation on A's end, or through rotation on B's end. With this understanding, the rest can be understood by reading the official analysis. <br /><br />
4. Hamiltonian Tour: the key is how to combine established cycles. Suppose we have two cycles 'SENW' and 'SENW' next to each other, if we know the relative orientation of the two smaller cycles, we can combine the two cycles by changing the neighboring flow. e.g. if the second cycle is on the right of the first cycle, we can make the two cycles 'SEEW' and 'WENW' by changing first cycle's thrid edge flow, and the second cycle's first edge flow. To obtain the relative orientation of neighboring cycles, we use an iterative dfs traversal to record the relative positions.<br />
