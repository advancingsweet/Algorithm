# 1.算法小白
2023/9/6 记录自己的算法刷题历程

## 学习方法总结

- 学习一个新的知识点，应该弄懂它的由来、特性、使用的场景以及所能解决的问题等，而非死记硬背，却不擅长应用！
- 对于暂时无法理解的知识点，不要死扣不放，适当重拿轻放更益于学习。或许当学到后面的某一个章节时，会突然发现之前不理解的知识点迎刃而解！

******

# 2.学习路线





# 3.知识点

## 1.string

> 1. **stoi()**
>
>    > `stoi()`函数是一种常用的编程函数，用于将字符串转换为整数（string to integer）。它可以将表示数字的字符串转换为对应的整数值。
>    >
>    > 在大多数编程语言中，包括C++、Python和Java，`stoi()`通常是一个内置的函数或方法。它接受一个字符串作为输入，并返回一个整数。以下是Python中的示例：
>    >
>    > ```python
>    > number_string = "42"
>    > number = int(number_string)  # 使用内置的int()函数
>    > print(number)  # 输出：42
>    > ```
>    >
>    > 在这个示例中，使用内置的`int()`函数将字符串`"42"`转换为整数值`42`。在C++中，`stoi()`函数的用法类似：
>    >
>    > ```cpp
>    > #include <iostream>
>    > #include <string>
>    > 
>    > int main() {
>    >     std::string number_string = "42";
>    >     int number = std::stoi(number_string);
>    >     std::cout << number << std::endl;  // 输出：42
>    >     return 0;
>    > }
>    > ```
>    >
>    > 在C++中，`stoi()`函数是`<string>`库的一部分，用于将字符串转换为整数。
>    >
>    > 需要注意的是，如果字符串无法转换为整数，根据编程语言的不同，可能会抛出异常或错误。在编写代码时，需要适当处理这些情况。

# 4.文件树

```
Algorithm:.
│  readme.md
│  tree.txt
│  
├─Contest
│  │  gameModel.md
│  │  
│  ├─AcWing
│  │      第 126 场周赛.md
│  │      
│  └─Leetcode
│          第 367 场周赛.md
│          第115场双周赛.md
│          
├─Question
│  │  myAlgorithmModel.md
│  │  
│  ├─Tree
│  │  │  myAlgorithmModel.md
│  │  │  readme.md
│  │  │  
│  │  ├─Leetcode
│  │  │  ├─102. 二叉树的层序遍历
│  │  │  │  │  advancedLevel.cpp
│  │  │  │  │  feelings.md
│  │  │  │  │  oneLevel.cpp
│  │  │  │  │  
│  │  │  │  └─Improve
│  │  │  ├─116. 填充每个节点的下一个右侧节点指针
│  │  │  │      ErrorCode.cpp
│  │  │  │      feelings.md
│  │  │  │      TreeBFS.cpp
│  │  │  │      
│  │  │  ├─117. 填充每个节点的下一个右侧节点指针 II
│  │  │  │      advancedLevel.cpp
│  │  │  │      feelings.md
│  │  │  │      oneLevel.cpp
│  │  │  │      
│  │  │  ├─199. 二叉树的右视图
│  │  │  │      advancedLevel.cpp
│  │  │  │      feelings.md
│  │  │  │      oneLevel.cpp
│  │  │  │      
│  │  │  ├─429. N 叉树的层序遍历
│  │  │  │      advancedLevel.cpp
│  │  │  │      feelings.md
│  │  │  │      oneLevel.cpp
│  │  │  │      
│  │  │  ├─515. 在每个树行中找最大值
│  │  │  │      advancedLevel.cpp
│  │  │  │      feelings.md
│  │  │  │      oneLevel.cpp
│  │  │  │      
│  │  │  ├─572. 另一棵树的子树
│  │  │  │      Code.cpp
│  │  │  │      readme.md
│  │  │  │      
│  │  │  └─637. 二叉树的层平均值
│  │  │          advancedLevel.cpp
│  │  │          feelings.md
│  │  │          oneLevel.cpp
│  │  │          
│  │  └─代码随想录
│  │          111. 二叉树的最小深度.md
│  │          222. 完全二叉树的节点个数.md
│  │          257. 二叉树的所有路径.md
│  │          5.二叉树的层次遍历.md
│  │          559. N 叉树的最大深度.md
│  │          8.对称二叉树.md
│  │          test.cpp
│  │          
│  ├─二分查找
│  │      33. 搜索旋转排序数组.md
│  │      34. 在排序数组中查找元素的第一个和最后一个位置.md
│  │      35. 搜索插入位置 .md
│  │      69. x 的平方根 .md
│  │      AcWing 790. 数的三次方根.md
│  │      readme.md
│  │      
│  ├─动态规划
│  │      300. 最长递增子序列.md
│  │      494. 目标和.md
│  │      674. 最长连续递增序列.md
│  │      
│  ├─数据结构
│  │      1.两数之和.md
│  │      2530. 执行 K 次操作后的最大分数.md
│  │      
│  ├─数组
│  │      209. 长度最小的子数组.md
│  │      79.最小覆盖字串.md
│  │      904. 水果成篮.md
│  │      myAlgorithmModel.md
│  │      
│  ├─树
│  │      108. 将有序数组转换为二叉搜索树.md
│  │      501. 二叉搜索树中的众数.md
│  │      
│  └─贪心算法
│          45. 跳跃游戏 II.md
│          55. 跳跃游戏.md
│          
└─Resource
        readme.md
```

