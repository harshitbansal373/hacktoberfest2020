/*
Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one
node and does not need to go through the root.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root,int& ans)
    {
        if(!root)
            return 0;
        int l = helper(root->left,ans);
        int r = helper(root->right,ans);
        int tmp = max(root->val,max(l,r)+root->val);
        ans = max(ans,max(tmp,l+root->val+r));
        return tmp;
    }
    int maxPathSum(TreeNode* root) {
        
        if(!root)
            return 0;
        int sum = INT_MIN;
        helper(root,sum);
        return sum;
    }
};
