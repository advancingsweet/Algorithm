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
    vector<int> rightSideView(TreeNode* root) {
            vector<int>res;
            if(!root) return res;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                int sz = q.size();
                res.push_back(q.back()->val);
                for(int i = 0;i < sz;i ++){  // maybe the latest node's child is empty, so it must traversal and keep by queue.
                    TreeNode * temp = q.front();
                    q.pop();
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
            return res;
    }
};