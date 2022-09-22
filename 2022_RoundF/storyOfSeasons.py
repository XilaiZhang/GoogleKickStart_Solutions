
T=int(input())
from collections import defaultdict, deque
import heapq

for tt in range(1,T+1):
    D, N, X = [int(x) for x in input().split()]
    seeds = []
    pending_list = []
    days_deadline = []
    for i in range(N):
        quantity, growth_days, profit = [int(x) for x in input().split()]
        pending_list.append([growth_days, -profit, quantity])
        # beaware of days == D
        if growth_days < D:
            days_deadline.append(growth_days)
    pending_list.sort(key = lambda x: -x[0])
    days_deadline.append(D)
    days_deadline.sort()
 
    result  = 0
    previous_day = 0
    for current_day in days_deadline:
        # calculate profit for the intervals of days between [1 day before the current day, to previous_day]
        # i.e. current_day - 1 - previous_day + 1 == current_day - previous_day
        head_count = X * (current_day - previous_day)
        # add all crops that could only start from the previous_day (the previous cutoff)
        while pending_list and current_day > pending_list[-1][0]:
            growth_days, neg_profit, quantity = pending_list.pop()
            heapq.heappush(seeds, (neg_profit, quantity))
        while seeds and head_count > 0:
            neg_profit, quantity = seeds[0]
            profit = - neg_profit
            if head_count >= quantity:
                result += quantity * profit
                heapq.heappop(seeds)
                head_count -= quantity
            elif head_count < quantity:
                result += head_count * profit
                heapq.heappop(seeds)
                heapq.heappush(seeds, (neg_profit, quantity - head_count))
                head_count = 0
        previous_day = current_day
    
    print("Case #"+str(tt)+": "+str(result))
    

