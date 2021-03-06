# 两个链表的第一个公共点
[题目链接](https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

## 题目描述
输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

## 题目要求
时间限制：C/C++ 1秒，其他语言2秒 空间限制：C/C++ 32M，其他语言64M 热度指数：310626
本题知识点： 链表

## 解题思路
1. 暴力法: 用地一个链表中的每个元素去跟第二个链表中的元素逐个对比,直到找到地一个相同的节点．
2. 尾部搜索法: 因为两个链表最终会汇集到一起，所以只需要从末尾开始到头逐个便利，直到上一个节点不相同为止，hash_map
3. 等长法: 先遍历一遍找到两个链表的长度，使两个链表等长然后一起便利两个链表直到地一个相同节点.
4. 巧妙: 扫描两个链表，地一个到达尾部的链表赋值为第二个链表，因为两个链表和的总长度相同，最终会汇集到一起.