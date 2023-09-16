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
    stack<TreeNode *> st;
    // find Node
    void find(TreeNode *root, int val)
    {
        if (!root)
            return;
        if (root->val == val)
            st.push(root);
        find(root->left, val);
        find(root->right, val);
    }

    // judge the value
    bool isSame(TreeNode *lc, TreeNode *rc)
    {
        if (!rc && !lc)
            return true;
        else if (lc && rc && lc->val == rc->val)
            return isSame(lc->left, rc->left) && isSame(lc->right, rc->right);
        else
            return false;
    }

    // check
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;
        find(root, subRoot->val);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            if (isSame(cur, subRoot))
                return true;
        }
        return false;
    }
};