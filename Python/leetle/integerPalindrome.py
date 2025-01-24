"""
Write a function solve that checks whether an integer is a palindrome without converting it to a string.

TWO POINTERS, MATH, INTEGER, PALINDROME
"""

def solve(num):
  if num < 0 or (num%10 == 0 and num != 0):
    return False
  elif num < 10:
    return True
  rest = 0
  while num > rest:
    rest = rest*10+num%10
    num = num//10
  if num == rest or num == rest//10:
    return True
  else:
    return False
  
print(solve(121)) # True