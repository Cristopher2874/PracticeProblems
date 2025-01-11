"""
Write a function solve that finds the first missing positive integer given an unsorted list. That is, the smallest positive integer not in the list.

Example:
Input: [3,4,-1,1]
Output: 2 
"""

def firstMissingPositive(nums):
    maxNum = max(nums)
    if maxNum < 0:
        return 1
    for i in range(1,maxNum):
        if i not in nums:
            return i
    return maxNum+1

print(firstMissingPositive([3,2,4,-1,1]))