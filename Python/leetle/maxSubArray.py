def solve(nums):
  if len(nums) == 1: 
    return nums[0]
  size=1
  back = 0
  maxSum = 0
  temp = 0
  while size <= len(nums):
    for j in range(back,size):
      for i in range(back,size):
        temp = temp + nums[i]
      if maxSum <= temp:
        maxSum = temp
      back = back + 1
      temp = 0
    size = size + 1
    back = 0
  return maxSum

def main():
  nums = [5,4,-1,7,8]
  print(solve(nums))

if __name__ == "__main__":
    main()