"""
Write a function solve that checks if a string is a palindrome, considering only alphanumeric characters and ignoring case.

Example:
Input: "A man, a plan, a canal: Panama"
Output: True 

STRING
"""

def solve(s):
  filter=''.join(char for char in s if char.isalnum()).lower()
  return filter == filter[::-1]

print(solve("A man, a plan, a canal: Panama")) # True
print(solve("race a car")) # False