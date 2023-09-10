input()
nums = input().split(' ')
dict_sort = dict()
dict_idx = dict()
for num in nums:
    dict_sort[num] = 0
sorted_nums = sorted(map(int, dict_sort.keys()))
for n in range(len(sorted_nums)):
    dict_idx[str(sorted_nums[n])] = n
for num in nums:
    print(dict_idx[num], end=" ")
