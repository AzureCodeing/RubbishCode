# 调整数组顺序使奇数位于偶数前面
[题目链接](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

## 题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

## 题目要求
时间限制：C/C++ 1秒，其他语言2秒 空间限制：C/C++ 32M，其他语言64M 热度指数：683209
本题知识点： 数组

## 补充
冒泡排序法:
```
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> a = {1, 4, 5, 9, 2, 3, 5};

void sort(std::vector<int> &array)
{
    for(int i = 0; i < array.size(); i++){
        for(int j = 0; j < array.size() - i - 1; j++){
            if(array[j] > array[j + 1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }    
}

int main(int argc, char *argv[])
{
    sort(a);
    for(auto vec: a){
        std::cout << vec;
    }
    std::cout << std::endl;
}
```


