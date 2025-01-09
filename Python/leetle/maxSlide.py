"""
Write a function solve that returns the maximum number in each window of size k sliding from left to right in a list. Your function should return a list of ints.

Example:
Input: [1,3,-1,-3,5,3,6,7], k=3
Output: [3,3,5,5,6,7] 

ARRAY SLIDING WINDOW
"""

def maxSlide(nums, k):
    ans = []
    for i in range(0,len(nums)-(k-1)):
        temp = nums[i:i+k]
        ans.append(max(temp))
    return ans

lista = maxSlide([1,3,-1,-3,5,3,6,7], 3)

for num in lista:
    print(num)