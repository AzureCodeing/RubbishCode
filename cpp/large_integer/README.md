# 大整数运算操作

## 意义
在linux环境下的c/c++语言中整数所能够表示数值的范围是有限制的：
* `unsigned int`:  0～4294967295   (10位数，4e9)
* `int`:  -2147483648～2147483647  (10位数，2e9   2^31 - 1)   
* `long long`:  -9223372036854775808～9223372036854775807  (19位数， 9e18 ) 2^63 - 1
* `unsigned long long`: 0～18446744073709551615  (20位数，1e19)  2^64 - 1  
当计算的数字超过了`unsigned long long`所能够表示的范围就会溢出，此时通常整数运算出来的结果不是正确的，这时候就需要利用其它算法来替代之前整数的计算规则。

## 代码分布
- [*] 加法：add.cpp
- [*] 减法：sub.cpp
- [*] 乘法：multiply.cpp
- [ ] 除法：None
- [*] 测试: test.cpp

## 思路
一般常见的大整数表示方法有两种：数组法和字符串法，我们这里使用了字符串的表示方法，因为字符串和整数之间的转化比较方便。

### 加法
定义:
```
std::string large_integer_add(const std::string &input_a, const std::string &input_b)
```
计算过程:
1. 计算两个输入字符串的长度，并去除最长字符串的长度
2. 从两个字符串的末尾开始到字符串的头为止，分别取出每一位字符并将他们转换为数字
3. 将两个数字和上一位的进位相加，计算出下一位的进位以及当前位的数
4. 循环执行`2-3`过程直到两个数字的每一位都被计算


### 减法
定义:
```
//判断两个字符串所表示的数字那个更大 true: a < b, false: a < b
bool mystrcmp(const std::string &input_a, const std::string &input_b)
//计算a-b
std::string large_integer_sub(const std::string &input_a, const std::string &input_b)
```

计算过程:
1. 首先判断要计算的两个数哪个大，判断计算出来的结果是整数还是负数
2. 根据判断出来的结果改变large_integer_sub（）函数的参数保证总是`减数>=被减数`
3. 从两个字符串的末尾开始到字符串的头为止，分别取出每一位字符并将他们转换为数字
4. 处理借位数字
5. 将两个数字进行相减，如果结果为负则需要借位后进行计算，如果结果为正则直接得出结果
6. 循环执行`3-5`过程直到两个数字的每一位都被计算


### 乘法
定义：
```
//大数加法
std::string large_integer_add(const std::string &input_a, const std::string &input_b)
//单个相乘
std::string single_mulitiply(const std::string &input_a, const char &input_b)
//大数相乘
std::string large_integer_mulitiply(const std::string &input_a, const std::string &input_b)
```

计算过程:
按照正常的乘法计算法则进行处理计算，例如`11*22`,可以拆成`11*2+11*2*10`。
1. 将两个数的其中一个（输入a）拆成一位数字，并跟另外一个输入的多位数字(输入b)进行相乘,直到(输入a)的每一位数都经过拆分计算。
2. 将计算的结果错项相加