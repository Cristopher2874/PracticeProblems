def solve(n):
    rev = 0
    temp = abs(n)
    while temp > 0:
      rev = rev * 10 + temp % 10
      temp = temp // 10
    if rev > 2**32 -1 or rev < -2**31:
        return 0
    elif n < 0:
      return -rev
    else:
        return rev
  
print(solve(-123)) # 321