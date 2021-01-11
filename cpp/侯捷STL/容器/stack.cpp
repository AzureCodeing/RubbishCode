#include <iostream>
#include <stack>
#include <deque>

//参考: https://zh.cppreference.com/w/cpp/container/stack
//FILO: 先入后出
int main(int argc, char *argv[])
{
    //1. 构造
    std::deque<int> deq {3, 1, 4, 1, 5};
    std::stack<int> c1(deq);

    //2. 访问
    std::cout << c1.top() << std::endl; //访问栈顶元素

    //3. 容量
    std::cout << "empty: " << c1.empty() << std::endl; //检查容器是否为空
    std::cout << "size: " << c1.size() << std::endl; //容器元素个数

    //4.修改器
    c1.push(10); //尾部插入元素
    c1.pop(); //删除栈顶元素
}