# 从尾到头打印链表
[题目链接](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

## 题目描述
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

## 题目要求
时间限制：C/C++ 1秒，其他语言2秒 空间限制：C/C++ 32M，其他语言64M 热度指数：1213728
本题知识点： 链表

## 知识点
反转数组:
1. 左右互换，数组的第一项与最好一项呼唤，第二项与倒数第二项呼唤，以此类推直到数组中间位置.
```
vector<int> reverseArray(vector<int> a) {
        for(size_t i = 0; i < a.size()/2; i++){
        a[i] ^= a[a.size() -1 - i];
        a[a.size() -1 - i] ^= a[i];
        a[i] ^= a[a.size() -1 - i];
    }
    return a;
}
```

2. 新建一个数组b，从后往前遍历数组a,将元素push到b中
```
vector<int> reverseArray2(vector<int> a) 
{
    vector<int> temp;
    for(auto ite = a.end() - 1; ite >= a.begin();ite--){
        temp.push_back(*ite);
    }
    return temp;
}
```

3. c++11数组初始化配合标准库
```
vector<int> reverseArray3(vector<int> a)
{
    return {a.rbegin(), a.rend()};
}
```

4. 标准库函数reverse,需要包含头文件`#include<algorithm>`
```
vector<int> reverseArray4(vector<int> a)
{
    reverse(a.begin(),a.end());
    return a;
}
```