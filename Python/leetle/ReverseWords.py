"""
Write a function solve that reverses the words in a string. Words are separated by spaces.

Example:
Input: "the sky is blue"
Output: "blue is sky the" 
"""

def solve(s):
    s = s.split(" ") #O(n)
    result = ''.join((s[i]+" ") for i in range(len(s)-1,-1,-1)) #O(n^2)
    return result[:-1] #O(n)
# Time complexity: O(n^2) - O(n) for reverse iteration and O(n) for join method.

def bestSolve(s):
    return ' '.join(reversed(s.split()))
# Time complexity: O(n) - The split method, reversed method, and join method each iterate through the string, making the overall time complexity linear.

print(bestSolve("the sky is blue"))
