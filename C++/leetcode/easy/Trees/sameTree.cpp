/*
Given the root of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104

TREE DEPTH FIRST SEARCH / BREADTH FIRST SEARCH BINARY TREE
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *right, TreeNode *left) : val(x), left(left), right(right) {}
};

class Solution{
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        if (p == NULL && q == NULL) 
            return true;
        if (p == NULL || q == NULL)
            return false;
        queue<pair<TreeNode *, TreeNode *>> pLine;
        pLine.push({p, q});
        while (!pLine.empty()){
            TreeNode* curr = pLine.front().first;
            TreeNode* copy = pLine.front().second;
            pLine.pop();
            if((curr->left!= NULL && copy->left == NULL) || (curr->left == NULL && copy->left != NULL))
                return false;
            if((curr->right!= NULL && copy->right == NULL) || (curr->right == NULL && copy->right != NULL))
                return false;
            if (curr->val != copy->val)
                return false;
            if (curr->left != NULL && copy->left != NULL){
                pLine.push({curr->left, copy->left});
                curr->left = NULL;
                copy->left = NULL;
            }
            if (curr->right != NULL && copy->right != NULL){
                pLine.push({curr->right, copy->right});
                curr->right = NULL;
                copy->right = NULL;
            }
        }
        return true;
    } //Time O(n) Space O(n)
};

int main(){
    Solution s;
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    TreeNode* q = new TreeNode(1);
    q->right = new TreeNode(2);
    cout<<"Es: "<<s.isSameTree(p,q);
    return 0;
}