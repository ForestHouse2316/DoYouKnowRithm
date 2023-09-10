# 아무래도 힙을 구현해야할듯

N = int(input())
nums = []
for i in range(N):
    nums.append(int(input()))
nums.sort(reverse=True)
# print(nums)
if N == 1:
    print(0)
else:
    comp_time = nums.pop() + nums.pop()
    nums.append(comp_time)
    for i in range(2, N-1):
        if nums[0] < nums[-1]:
            nums.insert(0, nums.pop())
        else:
            for j in range(len(nums)-2, -1, -1):
                if nums[-1] <= nums[j]:
                    nums.insert(j+1, nums.pop())
                    break
        # print(nums)
        temp = nums.pop() + nums.pop()
        comp_time += temp
        nums.append(temp)
    comp_time += nums[0] + nums[1]
    print(comp_time)

'''
10
90
80
70
63
65
60
12
10
20
99
'''