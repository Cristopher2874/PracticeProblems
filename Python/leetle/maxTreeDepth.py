"""
Write a function that finds the maximum depth of a binary tree. A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. The tree is represented as an array of nodes in level-order traversal. None indicates empty nodes.

Example:
Input: [3,9,20,None,None,15,7]
Output: 3 
BINARY TREE
"""


#Binary Tree Definition
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def arr2tree(arr):
    if not arr: return None
    root = TreeNode(arr[0])
    queue = [root]
    i=1
    while(i<len(arr)):
        curr = queue.pop(0)

        if arr[i]!=None:
            curr.left = TreeNode(arr[i])
            queue.append(curr.left)
        i+=1

        if i<len(arr) and arr[i]!=None:
            curr.right = TreeNode(arr[i])
            queue.append(curr.right)
        i+=1
    return root    

def solve(root):
    if not root: return 0
    leftDepth = solve(root.left)
    rightDepth = solve(root.right)
    return max(leftDepth, rightDepth)+1

arr = [3,9,20,None,None,15,7]
root = arr2tree(arr)
print(solve(root))