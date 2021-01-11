#include <iostream>
#include <map> // for multimap


int main(int argc,  char *argv[])
{
    std::multimap<std::string, int> map1 = {
        {"a", 1},
        {"b", 2},
        {"a", 3},
        {"d", 4},
        {"a", 3},
        {"a", 3},
        {"a", 3},
        {"a", 3},
    };

    for(auto elemt: map1){
        std::cout << "[" << elemt.first << " : " << elemt.second << "]" << std::endl;
    }
    
    std::cout << map1.count("a") << std::endl;

    return 0;
}
