# [二分查找总结](https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E5%85%B6%E4%BB%96%E8%AF%AD%E8%A8%80%E7%89%88%E6%9C%AC)

<img src="https://raw.githubusercontent.com/advancingsweet/Image/main/image-20230917145242999.png" alt="image-20230917145242999" style="zoom: 33%;" />

## 1.基本问题

1. 插入与查找的区别

   1. 插入：先查再插
      1. 元素存在
      2. 元素不存在
   2. 查找
      1. 元素存在
      2. 元素不存在

2. 范围问题

   - `mid = right - 1` or `mid = right`
   - `mid = left + 1 `  or `mid = left`

3. while循环条件

   `while (left < right)` or `while (left <= right)`



## [2.统一模板](https://www.bilibili.com/video/BV1d54y1q7k7/?spm_id_from=333.337.search-card.all.click&vd_source=235a1e7b912d1c10826a324e11418122)

### 1.查找元素

```C++
int Find(int val, int *arr)
{
    int left = -1, right = sizeof(arr)/sizeof(arr[0]);
    while ((left + 1)!= right)
    {
        int mid = left + (right - left) / 2;  // 防止right + left 爆栈
        if (arr[mid] == val)
            return mid;
       	else if (arr[mid] > val)
            right = mid;
        else 
            left = mid;
    }
    return -1;
}
```

### 2.插入元素

```C++
int Insert(int val, int *arr)
{
	int left = -1, right = sizeof(arr)/sizeof(arr[0]);
    while ((left + 1)!= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= val)
            right = mid;
        else 
            left = mid;
    }
	return left; // 最后一个小于val值的元素下标
    //return right 第一个大于或等于val值得元素下标
}
```

```C++
int Insert(int val, int *arr)
{
	int left = -1, right = sizeof(arr)/sizeof(arr[0]);
    while ((left + 1)!= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > val)
            right = mid;
        else 
            left = mid;
    }
	return left; // 最后一个小于或等于val值的元素下标
    // return right  第一个大于val值得元素下标
}
```

<img src="https://raw.githubusercontent.com/advancingsweet/Image/main/image-20230917141631777.png" alt="image-20230917141631777" style="zoom: 33%;" />

<img src="https://raw.githubusercontent.com/advancingsweet/Image/main/image-20230917145200798.png" alt="image-20230917145200798" style="zoom: 33%;" />
