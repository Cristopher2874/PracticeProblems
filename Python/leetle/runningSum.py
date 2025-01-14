"""
Write a function solve that returns the running sum of a list. The running sum is the sum of all elements up to each index.

Example:
Input: [1,2,3,4]
Output: [1,3,6,10] 
"""

def solve(nums):
  sum = 0
  ans = []
  for num in nums:
    sum+=num
    ans.append(sum)
  return ans

def bestSolve(nums):
  for i in range(1, len(nums)):
    nums[i] += nums[i-1]
  return nums

print(solve([1,2,3,4])) # [1,3,6,10]