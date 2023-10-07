# [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/)

# 0.用时

<img src="https://raw.githubusercontent.com/advancingsweet/Image/main/image-20231007113843409.png" alt="image-20231007113843409" style="zoom: 67%;" />

# 1.题目总结

[很棒的题解](https://www.acwing.com/solution/content/63190/)

> 1. 变量命名实在是比较差劲
> 2. 许多函数语法欠缺
>
> 妙解
>
> 1. 利用哈希表`unordered_map<char,int>ht`统计 `t`中的字符个数，便于直接查找，每次都要遍历`t`。非常方便后续操作
> 2. 引入`cnt`记录滑动窗口中有效的字符个数，以此判别`t`是否是滑动窗口的子串
> 3. 通过移动`i`收入有效字符，移动`j`去除无效字符！！！
> 4. 利用`while (hs[s[j]] > ht[s[j]]) hs[s[j++]] --;` 移动`j`将无效字符去除, 不会碰到将有效字符去除，因为一旦碰到有效字符，会触动循环条件而跳出循环。因为有效字符 `hs[s[j]] <= ht[s[j]]`!!!

# 2.错误代码

## 2.1.法一：（未找到问题所在：通过样例96/267)

```C++
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>str;
        unordered_map<char,int>tstr;
        string sres;

        int res = 0x3f3f3f3f, j = 0, type = 0;
        int t_size = t.size();

        for (auto ch : t)
            tstr[ch]++;
        for (int i = 0, s_size = s.size(); i < s_size; i++)
        {
            if (++str[s[i]] == 1) type ++;
            if (type >= t_size)
            {
                bool suc = true;
                for (auto ch : t)
                    if (str[ch] != tstr[ch])
                    {
                        suc = false;
                        break;
                    }
                // 收集齐
                if (suc)
                {
                    if (i - j + 1 < res)
                    {
                        res = i - j + 1;
                        sres = s.substr(j,i - j + 1); // 采纳
                    }
                    for (;j <= i; j++)
                        if (!(--str[s[j]]) && tstr[s[j]])
                            break;
                    while (suc && !tstr[s[j]])
                    {
                        str[s[j]] -= 1;
                        j++;
                    }
                }
            }
        }
        return sres;
    }
};
```



******************

# 3.AC代码

## [3.1.1法一:](https://www.acwing.com/video/1419/) （y总yyds）

```C++
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>hs,ht;
        for (auto c:t)
            ht[c] ++;
        int cnt = 0;   // 记录有效字符的个数！！！
        string res;
        for (int i = 0,j = 0, sz = s.size(); i < sz; i ++)
        {
            hs[s[i]] ++;
            if (hs[s[i]] <= ht[s[i]])  // 判断收入的字符是否有效，有效则cnt++
                cnt++;
            while (hs[s[j]] > ht[s[j]]) hs[s[j++]] --;  // 移动j将无效字符去除, 不会碰到将有效字符去除，因为一旦碰到有效字符，会触动循环条件而跳出循环。
            if (cnt == t.size()) // 满足要求
            {
                if(res.empty() || res.size() > (i - j + 1))
                    res = s.substr(j,i - j + 1);
            }
        }
        return res;
    }
};
```

## 3.1.2.复杂度分析



**************

## 