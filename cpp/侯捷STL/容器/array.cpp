#include <iostream>
#include <algorithm> // for sort
#include <iterator> //for iterator
#include <array>

//参考: https://zh.cppreference.com/w/cpp/container/array

using namespace std;

int main(int argc, char *argv[])
{
    //1. 构造
    std::array<int, 3> a1{ {1, 2, 3} }; //c++11之前
    std::array<int, 3> a2 = {4, 5, 6}; //c++11之后
    
    //2. 元素访问
    std::cout << "a1.at(0): " << a1.at(0) << std::endl; //a1.at(0):随机访问
    std::cout << "a1[0]: " << a1[0] << std::endl;   //a1[0]: 随机访问
    std::cout << "a1.front: " << a1.front() << std::endl; //front: 访问地一个元素
    std::cout << "a1.back: " << a1.back() << std::endl; //back: 访问最后一个元素
    std::cout << "a1.data: " << a1.data() << std::endl; //data: 返回地一个元素的地址

    //2. 迭代器
    std::cout << "begin(): " << a1.begin()  //begin: 返回指向容器的地一个迭代器件
              << "\tcbegin(): " <<  *a1.cbegin() << std::endl; //cbegin: 作用同上 

    std::cout << "end(): " << (a1.end()-1)  //begin: 返回指向容器的尾部迭代器件
              << "\tcend(): " <<  *(a1.cend()-1) << std::endl; //cbegin: 作用同上 
 
    //3. 容量
    std::cout << "empty: " << a1.empty() << std::endl; //检查容器是否为空
    std::cout << "size: " << a1.size() << std::endl; //返回容器容纳元素个数
    std::cout << "max_size: " << a1.max_size() << std::endl; //返回可容纳最大元素数

    //4. 操作
    a1.swap(a2); //交换两个数组元素,前提是两个数组必须等长
    a1.fill(1); //以固定元素填充数组

    //支持容器操作
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), //reverse_copy: 逆向拷贝
                      std::ostream_iterator<int>(std::cout, " "));

    for(auto elemt: a1){
        std::cout << elemt << " ";
    }    
    std::cout << '\n';

    return 0;
}