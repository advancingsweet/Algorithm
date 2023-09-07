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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        double ave = 0;
        while (!q.empty())
        {
            int sz = q.size();
            ave = 0;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                ave += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            res.push_back(ave * 1.0 / sz);
        }
        return res;
    }
};