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
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode *lc = q.front();
            q.pop();
            TreeNode *rc = q.front();
            q.pop();
            if (!lc && !rc)
                continue; // 均为空
            else if (lc && rc && lc->val == rc->val)
            {
                q.push(lc->left), q.push(rc->right);
                q.push(lc->right), q.push(lc->left);
            }
            else
                return false;
        }
        return true;
    }

    // 递归
    // bool Symmetric(TreeNode *left, TreeNode *right)
    // {
    //     if (!left && !right)
    //         return true;
    //     else if (!left && right)
    //         return false;
    //     else if (left && !right)
    //         return false;
    //     else if (left->val != right->val)
    //         return false;
    //     return Symmetric(left->left, right->right) && Symmetric(left->right, right->left);
    // }
};