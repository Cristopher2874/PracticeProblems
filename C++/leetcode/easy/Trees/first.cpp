/*
94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [1,3,2]

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]

Input: root = []
Output: []

Input: root = [1]
Output: [1]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?

STACK TREE DEPTH-FIRST SEARCH BINARY TREE
*/

#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> line;
        vector<int> res;
        line.push(root);
        while(!line.empty()){
            TreeNode* curr = line.top();
            if(curr->left != NULL){
                line.push(curr->left);
                curr->left = NULL; // mark as visited
            }
            else{
                res.push_back(curr->val); // visit
                line.pop();
                if(curr->right != NULL){
                    line.push(curr->right);
                    curr->right = NULL; // mark as visited
                }
            }
        }
        return res;
    } // time O(n) each node is visited once space O(n) because of stack usage
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    vector<int> res = s.inorderTraversal(root);
    for(auto num : res){
        cout << num << " ";
    }
    return 0;
}