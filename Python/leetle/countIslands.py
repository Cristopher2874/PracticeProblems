"""
Write a function solve that counts the number of islands in a 2D grid. An island is surrounded by water (0s) and is formed by connecting adjacent lands (1s) horizontally or vertically.

Example:
Input: [
[1,1,0],
[0,1,0],
[1,0,1]]
Output: 3 
"""

def solve(grid):
    islands = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                islands += 1
                grid = dfs(grid, i, j)
    
    return islands

def dfs(grid, i, j):
    if i<0 or i>=len(grid) or j<0 or j>=len(grid[0]) or grid[i][j] == 0:
        return grid
    else:
        grid[i][j] = 0
        grid = dfs(grid, i+1, j)
        grid = dfs(grid, i-1, j)
        grid = dfs(grid, i, j+1)
        grid = dfs(grid, i, j-1)
    return grid

grid = [
    [1,1,0],
    [0,1,0],
    [1,0,1]]

print(solve(grid))