#include <iostream>
#include <string>
#include <deque>

//参考: https://zh.cppreference.com/w/cpp/container/deque
template<typename T>
std::ostream& operator<<(std::ostream& s, const std::deque<T>& v)
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'}; //字符数组中'\0'代表占位
    // 迭代并打印 deque 的值
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}


int main(int argc, char *argv[])
{
    //1. 构造
    std::deque<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};    // c++11 初始化器列表语法
    std::cout << "words1: " << words1 << '\n';
 
    std::deque<std::string> words2(words1.begin(), words1.end());    // words2 == words1
    std::cout << "words2: " << words2 << '\n';
 
    std::deque<std::string> words3(words1);    // words3 == words1
    std::cout << "words3: " << words3 << '\n';
 
    std::deque<std::string> words4(5, "Mo");    // words4 为 {"Mo", "Mo", "Mo", "Mo", "Mo"}
    std::cout << "words4: " << words4 << '\n';

    //2. 访问
    std::cout << "words1.at(0): " << words1.at(0) << std::endl; //words1.at(0):随机访问
    std::cout << "awords11[0]: " << words1[0] << std::endl;   //words1[0]: 随机访问
    std::cout << "words1.front: " << words1.front() << std::endl; //front: 访问地一个元素
    std::cout << "words1.back: " << words1.back() << std::endl; //back: 访问最后一个元素

    //2. 迭代器
    std::cout << "begin(): " << *words1.begin()  //begin: 返回指向容器的地一个迭代器件
              << "\tcbegin(): " <<  *words1.cbegin() << std::endl; //cbegin: 作用同上 

    std::cout << "end(): " << *(words1.end()-1)  //begin: 返回指向容器的尾部迭代器件
              << "\tcend(): " <<  *(words1.cend()-1) << std::endl; //cbegin: 作用同上 

    //3. 容量
    std::cout << "empty: " << words1.empty() << std::endl; //检查容器是否为空
    std::cout << "size: " << words1.size() << std::endl; //返回容器容纳元素个数
    std::cout << "max_size: " << words1.max_size() << std::endl; //返回可容纳最大元素数
    words1.shrink_to_fit(); //请求移开未使用的容量

    words2.clear(); //清除元素

    words1.insert(words1.begin()+1, "hello");//插入单个数
    // std::cout << "insert1: " << words1 << '\n'; //[the, hello, frogurt, is, also, cursed]
    words1.insert(words1.begin()+1, words3.begin(),words3.end()); //插入另一个vector的元素
    // std::cout << "insert2: " << words1 << '\n'; //[the, the, frogurt, is, also, cursed, hello, frogurt, is, also, cursed]

    words3.erase(words3.begin()+1); //擦除元素 
    // std::cout << "erase: " << words1 << '\n'; //[the, the, frogurt, is, also, cursed, hello, frogurt, is, also, cursed]

    words3.push_back("back"); //从后插入
    words3.push_front("front"); //从头插入

    words3.pop_back();//移除末尾元素
    words3.pop_front();//移除头部元素

    words3.resize(10, "world"); //设置可容纳元素个数并且以１进行填充，up
    words3.resize(3); //设置可容纳元素个数,down 若当前大小大于 count ，则减小容器为其首 count 个元素。

    swap(words1, words3);

    return 0;
}