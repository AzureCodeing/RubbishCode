#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::vector<std::string> s0 = {"hello", "world", "test"};

    for(auto str:s0){
        std::string s1 = str;
        std::sort(s1.begin(), s1.end());
        std::cout << s1 << std::endl;
    }

    return 0;
}