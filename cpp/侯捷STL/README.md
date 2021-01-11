# STL标准库
**使用一个东西而不懂其中的原理，不高明!!**

## 介绍
1. c++Standard Library(c++标准库)`70%~80%为模板库`
2. Standard Template Library(STL标准模板库)

标准库header filles形式呈现
* 标准库的header files不带副名(.h)例如`#include <vector>`
* 新式c header files不带副名(.h)例如`#include <cstdio>`
* 旧版的c header files(带有副名.h)任然可用`#include <stdio.h>`

## STL六大部分
* 容器(Containers): 各种数据结构,如`list`，`ｖector`,`deque`,`set`,`map`用来存放数据,从实现角度来看,STL容器是一种`class template`
* 分配器(Allocators):负责空间的管理配置，从实现角度看配置器是一个实现了动态空间配置，空间管理，内存释放的`class template`
* 算法(Algorithms): 常用的各种算法,如`sort`,`search`,`copy`,`erase`等从实现角度看，STL算法是一种`function template`
* 迭代器(Iterators): 扮演着容器与算法之间的黏和剂，所谓的**范型指针**,从实现的角度看,迭代器是一种将`operator*`,`operator++`,`operator--`,`operator->`等指针相关操作的重载class,每一个容器都有自己的迭代器，只有容器的设计者才知道怎么遍历自己的元素
* 仿函数(Functors): 行为类似函数，可作为算法的某种策略，一般函数指针可以视为狭义的仿函数
* 适配器(Adapter):一种用来修饰函数或者仿函数或者迭代器的东西,例如stack和queue看似是一种容器，但实际上只能算是一种容器的适配器，应为他完全的借助deque.
关系:
1. 分配器(Allocators)给容器(Cainers)分配空间
2. 算法(Algorithms)使用迭代器(Iterator)访问容器(Containers)中的元素
3. 仿函数(Functors)可以协助算法(Allocators)完成不同的策略变化
4. 适配器(Ａdapter)可以修饰或者嵌套仿函数(Functors)

```
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
    int ia[6] = {27, 210, 12, 47, 109, 83};     
    vector<int, allocator<int>> vi(ia, ia+6);
    
    cout << count_if(vi.begin(), vi.end(),
            notl(bind2nd(less<int>(), 40)));
}
```

> 1. `vector<int>`容器 
> 2. `allocator<int>`为分配器(一般默认不写)
> 3. `count_if()`为算法
> 4. `vi.begin()`和`vi.end()`叫做迭代器件
> 5. `bind2nd()`为函数适配器
> 6. `less<int>()`为仿函数

## 复杂度
1. O(1)或O(c): 为常数时间
2. O(n): 为线性时间
3. O(logn): 对数时间
4. O(n^2):　平方时间
5. O(n^3): 立方时间
6. O(2^n): 指数时间
7. O(nlogn): 基于线性及二次方中间的行为

## 前闭后开[ )区间
标准库规定,`c.begin()`所指向的是容器的地一个元素的起点,而`c.end()`所指的是**最后一个元素的下一个位置**,所以*(c.end())这个动作是危险的.
```
Container<T> c;
...
Container<T>::iterator ite = c.begin();
for(; ite!= c.end(); ++ite)
...
```

> c++11新遍历容器语法: 
1.
> ```
>for(int i: {2, 3, 5, 7, 9, 13, 17, 19}){
>    std::cout << i << std::endl;
> }
> ```
