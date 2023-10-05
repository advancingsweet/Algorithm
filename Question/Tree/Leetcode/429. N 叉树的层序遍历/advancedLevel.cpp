/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res; // Empty,end
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                Node *temp = q.front();
                q.pop();
                level.push_back(temp->val);
                for (int j = 0, cnt = temp->children.size(); j < cnt; j++)
                    q.push(temp->children[j]);
            }
            res.push_back(level);
        }
        return res;
    }
};