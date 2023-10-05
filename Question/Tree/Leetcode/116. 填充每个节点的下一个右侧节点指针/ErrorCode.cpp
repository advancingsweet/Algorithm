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

class Solution // the code is Error, I didn't settle it.  I kown the reason why the code couldn't pass! because the pre node's child node wasn't reserved to queue.
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
            Node *pre = q.front(); // get first node of the level.  the first node's child node didn't be reserved. so it was error.
            q.pop();
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                Node *cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                pre->next = cur;
                pre = cur;
            }
            pre->next = NULL;
        }
        return root;
    }
};