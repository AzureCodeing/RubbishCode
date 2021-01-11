#include <iostream>

//函数模板
template<typename T>
T min(const T &a, const T &b)
{
    return a < b? a : b; 
}


int main(int argc, char *argv[])
{
    int a = 1, b = 2;
    std::cout << "min(a,b): " << min(a,b) << std::endl;

    double c = 1.2, d = 1.5;

    std::cout << "min(c,d): " << min(c,d) << std::endl;
    return 0;
}