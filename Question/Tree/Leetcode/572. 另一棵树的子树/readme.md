# 题解

[question address](https://leetcode.cn/problems/subtree-of-another-tree/)

## 坑点

![image-20230915151552932](C:\Users\HongweiTang\AppData\Roaming\Typora\typora-user-images\image-20230915151552932.png)<img src="C:\Users\HongweiTang\AppData\Roaming\Typora\typora-user-images\image-20230915152032512.png" alt="image-20230915152032512" style="zoom:50%;" />

必须是相同结构和节点值的子树，而不是子集！！！所以判断是否是相同子树代码如下。

```C++
bool isSame(TreeNode *root, TreeNode *subtree)
    {
        if (!subtree && !root)
            return true;
        else if (root && subtree && root->val == subtree->val)
            return isSame(root->left, subtree->left) && isSame(root->right, subtree->right);
        else return false;
    }

```

如果仅仅是判断subtree是否是root的一个子集，那么isSame（）函数书写不同

```C++
bool isSame(TreeNode *root, TreeNode *subtree)  // 
    {
        if (!subtree)  // 不需要再判断root是否为空！！！
            return true;
        else if (root && subtree && root->val == subtree->val)
            return isSame(root->left, subtree->left) && isSame(root->right, subtree->right);
        else return false;
    }

```

