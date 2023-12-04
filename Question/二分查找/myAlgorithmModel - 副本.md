# [2300. 咒语和药水的成功对数](https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/)

# 0.用时



# 1.个人解题思路

> 如果利用双循环，则根据数据范围肯定会超时。于是采用单层循环+ 二分查找
>
> 1. 先对`potions`数组进行排序
>
> 2. 遍历`spells`数组   
>    $$
>    spells[i] * potions[j] >= success 
>     
>      \equiv potions[j] >= \lceil success / spells[i] \rceil
>    $$
>    
>
> 3. 所以只要利用二分查找找到满足要求的最小`potions[j]`即可



******************

# 2.AC代码

```C++

```

### 超内存

```C++
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) { 
        sort(potions.begin(),potions.end());
        vector<int>res(spells.size());
        for (int i = 0; i < spells.size(); i++){
            long long  x = success / spells[i];
            if (success % spells[i])
                x += 1;
            res[i] += bs(potions,x);
        }
        return res;
    }
    int bs(vector<int>vec,long long  x){
        int l = -1,r = vec.size();
        while(l + 1 != r){
            int mid = (l + r) >> 1;
            if (vec[mid] >= x)
                r = mid;
            else 
                l = mid;
        }
        return vec.size() - r;
    }
};
```



## 复杂度分析





# 3.题目总结





# 4.Look back

