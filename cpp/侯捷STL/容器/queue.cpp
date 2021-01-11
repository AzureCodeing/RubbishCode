#include <iostream>
#include <queue>
#include <deque>
//参考:https://zh.cppreference.com/w/cpp/container/queue
//FIFO先入先出

int main(int argc, char *argv[])
{
    //1. 构造
    std::deque<int> c1{3, 1, 4, 1, 5};
    std::queue<int> c2(c1);

    //2. 元素访问
    std::cout << "front: " << c2.front() << std::endl; //访问第一个元素
    std::cout << "back: " << c2.back() << std::endl; //访问最后一个元素

    //3. 容量
    std::cout << "empty: " << c2.empty() << std::endl; //检查容器是否为空
    std::cout << "size: " << c2.size() << std::endl; //容器元素个数

    //4.修改器
    c2.push(10); //尾部插入元素
    c2.pop(); //删除栈顶元素

    return 0;
}