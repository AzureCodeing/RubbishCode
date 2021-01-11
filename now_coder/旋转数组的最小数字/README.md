# 旋转数组的最小数字
[题目链接](https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

## 题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

## 题目要求
时间限制：C/C++ 3秒，其他语言6秒 空间限制：C/C++ 32M，其他语言64M 热度指数：824471
本题知识点： 查找

> min_element() 和 max_element()
头文件: `#include<algorithm>`
min_element() -- `取容器中的最小值`
用法:
```
#include<algorithm>

std::vector<int> a ={1,2,3,4,5,6};
auto min = min_element(a.begin(), a.endl());
std::cout << "最小值: " << *min << std::endl;
```

> max_element() -- `取容器中的最大值`
用法:
```
#include<algorithm>

std::vector<int> a ={1,2,3,4,5,6};
auto max = max_element(a.begin(), a.endl());
std::cout << "最小值: " << *max << std::endl;
```
