int maxPathSum(TreeNode* root)
{
    int ans = INT_MIN;
    DFS(root, ans);
    return ans;
}
int DFS(TreeNode* root, int &ans)
{
    if (!root) return 0;
    int left = max(0, DFS(root->left, ans));
    int right = max(0, DFS(root->right, ans));
    ans = max(ans, left + right + root->val);
    return max(left, right) + root->val;
}