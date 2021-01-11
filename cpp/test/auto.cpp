#include <iostream>

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) // 返回类型依赖于模板形参
{                                     // C++14 开始可以推导返回类型
    return t+u;
}

auto main(int argc, char *argv[])->int
{
    std::cout << "hello " << std::endl;
    std::cout << add("hello","world") << std::endl;
    std::cout << add(1,2) << std::endl;
    return 0;
}

std::decltype