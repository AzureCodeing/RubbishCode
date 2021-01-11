#include <iostream>
#include <set>


//参考: https://zh.cppreference.com/w/cpp/container/set
int main(int argc, char *argv[])
{
    /************************set*****************************/
    //1. 构造
    std::set<std::string> a;   // (1) 默认初始化器
    a.insert("cat");
    a.insert("dog");
    a.insert("horse");
    for(auto& str: a) std::cout << str << ' ';
    std::cout << '\n';

    std::set<std::string> b(a.find("dog"), a.end());   // (2) 迭代器初始化器
    for(auto& str: b) std::cout << str << ' ';
    std::cout << '\n';

    std::set<std::string> c(a);  // (3) 复制构造函数
    c.insert("another horse");
    for(auto& str: c) std::cout << str << ' ';
    std::cout << '\n';

    std::set<std::string> d(std::move(a));  // (4) 移动构造函数
    for(auto& str: d) std::cout << str << ' ';
    std::cout << '\n';
    std::cout << "moved-from set is ";
    for(auto& str: a) std::cout << str << ' ';
    std::cout << '\n';

    std::set<std::string> e {"one", "two", "three", "five", "eight"};  // (5) initializer_list 构造函数
    for(auto& str: e) std::cout << str << ' ';
    std::cout << '\n';

    //2. 迭代器
    auto ite_beg = a.begin(); //返回指向容器第一个元素的迭代器
    auto ite_end = a.end(); //返回指向容器最后一个元素的迭代器

    //3. 容量
    std::cout << "empty: " << a.empty() << std::endl; //判断容器是否为空
    std::cout << "size: " << a.size() << std::endl; //输出容器元素个数
    std::cout << "max_size: " << a.max_size() << std::endl; //返回容器可容纳的最大元素

    //4. 修改器
    a.erase("cat"); //擦出元素
    a.clear(); //清除所有元素
    
    //5. 查找
    a.find("cat");

    /************************set*****************************/
    const std::multiset<int> init = {1, 2, 3, 4, 1, 2, 3, 1, 1, 1, 2};

    for(auto elemt: init){
        std::cout << elemt << " ";
    }
    std::cout << std::endl;

    std::cout << "count: " << init.count(1) << std::endl;
    return 0;

}