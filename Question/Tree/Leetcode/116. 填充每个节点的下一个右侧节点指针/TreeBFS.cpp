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
            Node *pre = q.front(); // get first node of the level
            q.pop();
            int sz = q.size();
            for (int i = 0; i <= sz; i++)
            {
                if (pre->left) // 虽然是完美二叉树，但是叶子节点没有孩子！所以必须进行判断。
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