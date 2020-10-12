    1                1
   / \                2
  2   5        ->      3
 / \                    4
3  4                     5


Implementation:

void flatten(TreeNode* root)
{
    TreeNode *cur = root;
    while (cur)
    {
        if (cur->left)
        {
            TreeNode *tmp = cur->left;
            while (tmp->right) tmp = tmp->right;
            tmp->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}