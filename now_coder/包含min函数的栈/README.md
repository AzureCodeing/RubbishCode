# 包含min函数的栈
[题目链接](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

## 题目描述
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。

## 题目要求
时间限制：C/C++ 1秒，其他语言2秒 空间限制：C/C++ 32M，其他语言64M 热度指数：403086
本题知识点： 栈

## 解题思路
1. 创建一个新的栈用来存放最小值
2. 当新加入一个节点时候判新节点和已有的最小值谁更小,并更新存放最小值的栈
3. 当栈pop时，最小值栈跟着一起释放