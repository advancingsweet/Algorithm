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
    vector<vector<int>>res;  // 第一层vector代表树的层次，第二层vector存放每一层树的节点
    vector<vector<int>> levelOrder(TreeNode* root) {
       if(!root) return res;  // 根节点单独判断
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){   //while循环控制从上往下一层层遍历 ： 层次不可知，用while更好！
           int sz = q.size();
            vector<int>level;
            for(int i = 0;i < sz;i ++){ 
                // for 循环控制每一层从左向右遍历： 每一层的元素个数可知，用for,并且可以将每一层的元素个数区分开！！！
                TreeNode*cur = q.front();
                q.pop();
                level.push_back(cur->val);   // 存放至队列中的节点在存放之前已经被判断是否为空，所以无需再进行判断。（若进行判断也可） 
                if(cur->left) 
                    q.push(cur->left);
                if(cur->right) 
                    q.push(cur->right);
            }
            res.push_back(level); // 将每一层的数据单独存放，直接放入到 vector<vector<int>>res 中！
       }
       return res;
    }
};