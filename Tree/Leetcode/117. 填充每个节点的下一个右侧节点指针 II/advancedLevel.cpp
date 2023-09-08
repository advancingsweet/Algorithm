/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *pre = q.front();
            q.pop();
            for (int i = 0, sz = q.size(); i <= sz; i++)
            {
                if (pre->left)
                    q.push(pre->left);
                if (pre->right)
                    q.push(pre->right);
                if (i == sz)
                    break;
                Node *cur = q.front();
                q.pop();
                pre->next = cur;
                pre = cur;
            }
            pre->next = NULL;
        }
        return root;
    }
};