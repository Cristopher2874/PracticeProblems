"""
Write a function solve that counts the number of vowels (a,e,i,o,u) in a string, ignoring case.

Example:
Input: "Hello World"
Output: 3 

SET STRING
"""

def solve(text):
    vowels = {'a','e','i','o','u'} #set for fast lookup
    count = 0
    for char in text:
        if char.lower() in vowels:
            count += 1
    return count
# time complexity: O(n) space complexity: O(1)

print(solve("Hello World"))