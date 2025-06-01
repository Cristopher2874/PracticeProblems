/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,3,4,4,3]
Output: true

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100

TREE DEPTH FIRST SEARCH BREATH FIRST SEARCH BINARY TREEE
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), right(nullptr), left(nullptr) {}
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
    TreeNode(int x, TreeNode* right, TreeNode* left) : val(x), right(right), left(left) {} 
};

class Solution{
public:
    bool isSymmetric(TreeNode* root){
        if(root==nullptr) return true;
        return true;
    }
};