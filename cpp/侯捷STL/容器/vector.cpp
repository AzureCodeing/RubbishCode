#include <iostream>
#include <string>
#include <vector>

//参考: https://zh.cppreference.com/w/cpp/container/vector
//当容量不够时候空间是呈两倍增长


void print_vec(const std::vector<int>& vec)
{
    // 支持带范围 for 循环
    for (auto x: vec) {
         std::cout << ' ' << x;
    }
    std::cout << '\n';
}

int main(int argc, char *argv[])
{
    //1. 构造
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2(vec1.begin(), vec1.begin()+3);
    std::vector<int> vec3(vec2);
    std::vector<std::string> vec4(5, "hello");


    //2. 访问
    std::cout << "vec1.at(0): " << vec1.at(0) << std::endl; //at
    std::cout << "vec1[0]: " << vec1[0] << std::endl; //operator[]
    std::cout << "front: " << vec1.front() << std::endl;
    std::cout << "back: " << vec1.back() << std::endl;
    std::cout << "data: " << vec1.data() << std::endl;

    //3. 迭代器
    std::cout << "begin(): " << *vec1.begin()  //begin: 返回指向容器的地一个迭代器件
              << "\tcbegin(): " <<  *vec1.cbegin() << std::endl; //cbegin: 作用同上 

    std::cout << "end(): " << *(vec1.end()-1)  //begin: 返回指向容器的尾部迭代器件
              << "\tcend(): " <<  *(vec1.cend()-1) << std::endl; //cbegin: 作用同上 


    //4. 容量
    std::cout << "empty: " << vec1.empty() << std::endl;
    std::cout << "size: " << vec1.size() << std::endl;
    vec1.reserve(100000); //预留存储空间，如果vector元素个数非常多建议提前reverse来减少扩充次数
    vec1.shrink_to_fit(); //请求移开未使用的容量
    std::cout << "capacity: " << vec1.capacity() << std::endl; //返回当前存储空间能够容纳的元素个数
    std::cout << "max_size: " << vec1.max_size() << std::endl; 

    //5. 修改器
    vec2.clear(); //清除内容

    vec3.insert(vec3.begin()+1, 4);//插入单个数
    vec3.insert(vec3.begin()+1, vec1.begin(),vec1.end()); //插入另一个vector的元素
    print_vec(vec3);

    vec3.erase(vec3.begin()+1); //擦除元素
    print_vec(vec3);
    
    // std::cout << "增长后: " << vec1.capacity() << std::endl; //(5)
    vec1.push_back(1);
    // std::cout << "增长前: " << vec1.capacity() << std::endl; //二倍增长(10)

    vec1.pop_back();//移除末尾元素

    vec1.resize(10, 1); //设置可容纳元素个数并且以１进行填充，up
    vec1.resize(3); //设置可容纳元素个数,down 若当前大小大于 count ，则减小容器为其首 count 个元素。

    return 0;
}