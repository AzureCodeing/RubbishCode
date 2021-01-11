#include <iostream>
#include <algorithm>

using namespace std;

std::vector<int> a = {1, 4, 5, 9, 2, 3, 5};


template<typename num, typename iter>
iter my_find(num i, iter begin, iter end)
{
    while(begin != end && *begin != i) ++begin;
    return begin;
}



int main(int argc, char *argv[])
{
    auto iter = my_find(4, a.begin(), a.end());
    std::cout << "iter: " << *iter << std::endl;
    return 0;
}