# 整数中出现1的次数(从1到n整数中出现1的次数)
[题目链接](https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

## 题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

## 题目要求
时间限制：C/C++ 1秒，其他语言2秒 空间限制：C/C++ 32M，其他语言64M 热度指数：270730
本题知识点： 查找 数学

## 解题思路
如果要计算百位上1出现的次数，它受三个方面的影响:`百位上的数字`,`百位以下的(低位)的数字`,`百位以上(高位)的数字`
1. 如果百位上的数字为0,百位上出现1的次数由更高位决定，例如输入数据为12013,则可以知道百位出现1的情况可能是100~199,1100~1199...11100~11199一共1200个,可以看出其12个100构成(更高位数x当前位数)
2. 如果百位上的数字为1,则百位上出现1的次数不仅受到高位的影响而且还受到低位的影响,比如：12113，则可以知道百位受高位影响出现的情况是：100~199，1100~1199,2100~2199，，....，11100~11199，一共1200个。和上面情况一样，并且等于更高位数字（12）乘以 当前位数（100）。但同时它还受低位影响，百位出现1的情况是：12100~12113,一共114个，等于低位数字（113）+1。
3. 如果百位上数字大于1（2~9），则百位上出现1的情况仅由更高位决定，比如12213，则百位出现1的情况是：100~199,1100~1199，2100~2199，...，11100~11199,12100~12199,一共有1300个，并且等于更高位数字+1（12+1）乘以当前位数（100）。