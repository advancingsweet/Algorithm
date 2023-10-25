# [2698. 求一个整数的惩罚数](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/)

# 0.用时



# 1.个人解题思路

1. 对于数`123456`,可以划分为：`(1,2,3) (4,5,6)`两个集合（举例）， 然后在每个可以继续划分（或者直接组合），`(1,2) (3) (4) (5,6)`再继续划分（或者直接组合在一起。便知这是一个需要不断划分组合的过程**（过程重复，递归！！！）**，然后如果分组`(1,2) (3) (4) (5,6)`不满足，则需要回归上一状态`(1,2,3) (4,5,6)`重新划分，可划分为：`(1,2,3) (4,5) (6)` （划分情况多种，此任举一例）。**（此为过程为回溯！！！）**
2. 通过递归不断去给元素划分组合，然后通过回溯不断的去重新组合，直到找到最优划分组合解。
3. **最最最重要！！！ 这是按顺序排列分组，所以不存在归位这一步，即：`res -= i * i`，如果是不按顺序排列分组，那么必须有归位这一步骤`res -= i * i`**

******************

# 2.AC代码

```C++
class Solution {
public:
    bool dfs(string str,int st,int tol,int target)
    {
        if (st == str.size())
            return target == tol;  // 不是 st == str.size() - 1;
        int val = 0;  //不能 直接将tol赋值给val,因为各个分组是相加，而不是 val * 10 + str[i] - '0'
        for (int i = st; i < str.size(); i++){
            val = val * 10 + str[i] - '0';   // 将字符转化为数字。（int）char
            if (val + tol> target)
                break;
            if (dfs(str,i + 1,val + tol,target))
                return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1;i <= n; i++){
            string str = to_string(i * i);
            if (dfs(str,0,0,i))
                res += i * i;
        }
        return res;
    }
};
```

## 复杂度分析





# 3.题目总结

> 1. **第一次递归到最低端：（1）（2）（3）（4）（5）（6）（7）== 1 + 2 + 3 + 4 + 5 + 6**
>
> ![image-20231025154341262](https://raw.githubusercontent.com/advancingsweet/Image/main/image-20231025154341262.png)
>
> 2. **经过数次递归和回溯过程：（1，2，3） （4，5）（6）（7）== 123 + 45 + 6 + 7**
>
> ![image-20231025154258458](https://raw.githubusercontent.com/advancingsweet/Image/main/image-20231025154258458.png)
>
> 



# 4.Look back

