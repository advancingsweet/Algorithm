# [Leetcode 第 367 场周赛](https://leetcode.cn/contest/weekly-contest-367/)

# 0.总用时



# 1.题目一

> [100096. 找出满足差值条件的下标 I](https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i/)

```C++
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int min_index = 0, max_index = 0;
        for (int i = indexDifference; i < nums.size(); i++){
            int ind = i - indexDifference;
            if (nums[ind] > nums[max_index])
                max_index = ind;
            else if (nums[ind] < nums[min_index])
                min_index = ind;
            if (abs(nums[i] - nums[min_index]) >= valueDifference)
                return {min_index,i};
            if (abs(nums[i] - nums[max_index]) >= valueDifference)
                return {max_index,i};
        }
        return {-1,-1};
    }
};
```

## 代码总结

> 题目一和题目三仅仅是数据范围不同。



# 2.题目二

> [100084. 最短且字典序最小的美丽子字符串](https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/)

```C++
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int>vec;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                vec.push_back(i);
        string p = "", res = "";
        for (int i = 0; i + k - 1 < vec.size(); i++) {
            p = s.substr(vec[i], vec[i + k - 1] - vec[i] + 1);

            if (!res.size() || p.size() < res.size())
                res = p;
            
            else if (p.size() == res.size()) {
                for (int j = 0; j < res.size(); j++) {
                    if (res[j] < p[j])
                            break;
                    else if (p[j] < res[j]) {
                        res = p;
                            break;
                    }
                }
            }
            
        }
        return res;
    }
};
```

## 本人代码（未ac）

```C++
    class Solution {
    public:
        string shortestBeautifulSubstring(string s, int k) {
            string vec = "";
            int val1 = 0, val0 = 0;

            for (int i = 0, j = 0; i < s.size(); i++) {  // 查找
                // 统计
                if (s[i] == '1')
                    val1++;
                else
                    val0++;

                if (val1 == k) {
                    string str = s.substr(j, i - j + 1);
                    // 更新
                    if (!vec.size() || str.size() < vec.size())
                        vec = str;
                    else if (str.size() == vec.size()) {
                        for (int m = 0; m < str.size(); m++) {
                            if (str[m] == '0' && vec[m] == '1') {
                                vec = str;
                                break;
                            }
                        }
                    }
                    // 删除
                    while (val1 >= k - 1) {
                        if (s[j] == '1')
                            val1--;
                        else if (s[j] == '0')
                            val0--;
                        j++;
                    }
                    j--; // 添加最后一个
                    val1++; // val1 也得加回去啊！！！
                }

            }

            return vec;
        }
    };
```



## 题目总结

> 1. 利用双指针算法（未成功）
>
> 2. 先将所有`1`的位置进行统计，然后在利用区间差值进行计算
>
>    > 比较字典顺序时，不能只使用`if (p[j] < res[j]) res = p`  会将`p[j] > res[j]`这种情况直接跳过，所获得的字典序未必是最小！

# 3.题目三

> [100101. 找出满足差值条件的下标 II](https://leetcode.cn/problems/find-indices-with-index-and-value-difference-ii/)

```C++
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int min_index = 0,min_val = nums[0];
        int max_index = 0,max_val = nums[0];
        for (int i = indexDifference ; i < nums.size(); i ++)
        {
            int index = i - indexDifference;
            if (nums[index] < min_val){
                min_val = nums[index];
                min_index = index;
            }
            if (nums[index] > max_val){
                max_val = nums[index];
                max_index = index;
            }
            if (abs(max_val - nums[i]) >= valueDifference) return {i,max_index};
            if (abs(min_val - nums[i]) >= valueDifference) return {i,min_index};
        }
        return {-1,-1};
    }
};
```

## 题目总结

> 1. 题干有两个条件限制，此题通过先满足一个条件，然后通过一层循环遍历所以元素去寻找满足第二个条件的元素。
>
>    - `abs(i - j) >= indexDifference`
>
>    - ``abs(nums[i] - nums[j]) >= valueDifference``
>
>      



# 4.第四题

> [8026. 构造乘积矩阵](https://leetcode.cn/problems/construct-product-matrix/)

```C++
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>p(grid.size(),vector<int>(m));
        
        long long suf = 1;  // 后缀乘积
        for (int i = n - 1; i >= 0;i --)
            for (int j = m - 1; j >= 0; j--){
                p[i][j] = suf;
                suf = suf * grid[i][j] % MOD;
            }
        long long pre = 1; // 前缀乘积
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                p[i][j] = p[i][j] * pre % MOD;
                pre = pre * grid[i][j] % MOD;
            }

        return p;
    }
};
```

## 题目总结

> 1. 前缀乘法 + 后缀乘法
>
> 2. 不能所有元素直接相乘`all`然后再除所求元素的值。
>
>    > 1. 注意`nums[i]`的取值范围，如果存在0，那么数组均为零（也可以特判数组的情况，只有一个0，那么所得数组只有一个位置有数，其余均为0.如果0的个数不止一个，那么数组全为0
>    > 2. 由于在乘法运算中会对`12345`进行取余，所以无法通过`all`还原除`p[i][j]`之外其他数相乘再取模的值