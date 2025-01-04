def solve(nums):
    for i in range(0, len(nums) + 1):
        if i not in nums:
            return i
    


def main():
  nums = [3,0,1]
  print(solve(nums))

if __name__ == "__main__":
  main()