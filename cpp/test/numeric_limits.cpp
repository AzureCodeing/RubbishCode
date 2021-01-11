#include <iostream>
#include <limits>
int main(int argc, char *argv[])
{
    std::cout << "std::numeric_limits<double>::max(): " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "std::numeric_limits<double>::min(): " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "std::numeric_limits<int>::max(): " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "std::numeric_limits<int>::min(): " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "std::numeric_limits<char>::max(): " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "std::numeric_limits<char>::min(): " << std::numeric_limits<float>::min() << std::endl;
}