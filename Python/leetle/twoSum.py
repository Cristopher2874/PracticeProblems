def solve(nums, target):
  rest=[]
  ans = []
  for i in range(0,len(nums)):
    if nums[i] in rest:
      j = nums.index(target-nums[i])
      ans = [j,i]
      return ans
    rest.append(target-nums[i])  
  return ans

print(solve([2,7,11,15],9)) # [0,1]