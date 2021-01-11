#include <iostream>
#include <future> //for std::future
#include <functional>


/* Function函数 Args参数 */
//可变参数模板
template <typename Function, typename... Args>
typename std::result_of<Function(Args...)>::type
    add(Function&& fcn, Args&&... args)
{
    typedef typename std::result_of<Function(Args...)>::type return_type; //返回值类型
    return fcn(args...);
}

template <typename T>
void cpp_print(T& d1){
    std::cout << d1 << std::endl;
}

template <typename arg, typename... pack>
void cpp_print(arg d1, pack... p1){
    std::cout << d1 << " ";
    cpp_print(p1...);
}

int main(int argc, char *argv[])
{
    std::cout << add([](int a){return a;}, int(1)) << std::endl;
    std::cout << add([](int a, int b){return a+b;}, int(1), int(2)) << std::endl;
    std::cout << add([](std::string a, std::string b){return a+b;}, std::string("Hello"), std::string("World")) << std::endl;
    std::cout << add([](double a, double b){return a*b;}, double(3.14), double(2.0)) << std::endl;

    cpp_print(1,3.5,"hello");
    return 0;
}