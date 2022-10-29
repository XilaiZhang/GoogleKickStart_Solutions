
T=int(input())

for tt in range(1,T+1):
    N = int(input())
    numbers = [int(x) for x in input().split()]
    prefix = [0]
    for number in numbers:
        prefix.append(prefix[-1] + number)
    prefix_prefix = [0]
    for i in range(1, N+1):
        prefix_prefix.append(prefix_prefix[-1] + prefix[i])

    nearest_smaller_value = [N+1 for x in range(N+2)]
    stack_bigger_indices = []
    for index in range(N+1):
        while stack_bigger_indices and prefix[stack_bigger_indices[-1]] > prefix[index]:
            old_index = stack_bigger_indices.pop()
            nearest_smaller_value[old_index + 1] = index
        stack_bigger_indices.append(index)

    result = 0
    for start_pos in range(1, N+1):
        right_bound = nearest_smaller_value[start_pos] - 1
        if right_bound < start_pos:
            continue
        result += prefix_prefix[right_bound] - prefix_prefix[start_pos - 1] - (right_bound - start_pos + 1) * prefix[start_pos - 1]

    print("Case #"+str(tt)+": "+str(result))
    

