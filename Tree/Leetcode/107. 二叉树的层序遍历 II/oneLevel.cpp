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

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> res;
            if(!root) return res;    // Note: only return when root points NULL
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){  // if q is empty, return true!
                int sz = q.size();
                vector<int>level;
                for(int i = 0;i < sz;i ++){
                    TreeNode *temp = q.front();
                    q.pop();
                    level.push_back(temp->val);
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
               res.insert(res.begin(),level);
            }
            return res;
    }
};