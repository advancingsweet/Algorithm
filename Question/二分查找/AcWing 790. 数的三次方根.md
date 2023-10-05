## [AcWing 790. 数的三次方根](https://www.acwing.com/problem/content/792/)



# 1.题目总结

此题虽然为精度问题，但是然可以用模板进行解题，只不过所求精度应比此题要求精度**至少多两位**。 若题目精度要求为 x

```C++
int count = 100;
while (count--)
```

同样也可以：

​	`while (left + 1e-x-2 <= right)`



# 2.错误代码

## 2.1.法一：

```C++
#include<iostream>
using namespace std;

int main()
{
    double n;
    cin >> n;
    double left = -50, right = 50;
    while (left + 1e-7 != right)   //跟精度没关系，必须得限定循环次数，否则会超时。根据int类型数据为 2^32 -1, 循环可以进行100即可
    {
        double mid = left + (right - left) / 2.0;
        if (mid * mid * mid >= n)
            right = mid;
        else
            left = mid;
    }
    prdoublef("%.6lf",right);
    return 0;
}
```



******************

# 3.AC代码

## 3.1.1法一:

```C++
#include<iostream>
using namespace std;

int main()
{
    double n;
    cin >> n;
    double left = -50, right = 50;
    int count = 100;
    while (count --)  //  只要二分的次数足够，肯定会满足精度要求
    //while (left - right >= 1e-8)  虽然要求精度是6，精度为7时报错，以后都往后多保存两位
    {
        double mid = left + (right - left) / 2.0;
        if (mid * mid * mid >= n)
            right = mid;
        else
            left = mid;
    }
    printf("%.6lf",right);
    return 0;
}
```

## 3.1.2.复杂度分析


