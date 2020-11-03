#Problem to get the indices of two numbers such that they add up to target,
#for given array and target

def twoSum(nums,target):
    for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    print([i, j])


nums = []
n = int(input("Enter number of elements : "))
print("Enter values:")
for i in range(0, n):
            ele = int(input())
            nums.append(ele)
target = int(input("Enter target:"))
twoSum(nums,target)
#done
