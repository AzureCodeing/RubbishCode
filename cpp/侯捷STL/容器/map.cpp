#include <iostream>
#include <map>

template<typename Map>
void print_map(Map& m)
{
   std::cout << '{';
   for(auto& p: m)
        std::cout << p.first << ':' << p.second << ' ';
   std::cout << "}\n";
}

int main(int argc, char *argv[])
{
    /********************map***************************/
    //1. 构造
    std::map<std::string, int> map1; // (1) 默认构造函数
    map1["something"] = 69;
    map1["anything"] = 199;
    map1["that thing"] = 50;

    std::cout << "map1 = "; print_map(map1);

    std::map<std::string, int> iter(map1.find("something"), map1.end());  // (2) 范围构造函数
    std::cout << "\niter = "; print_map(iter);
    std::cout << "map1 = "; print_map(map1);

    std::map<std::string, int> copied(map1);  // (3) 复制构造函数
    std::cout << "\ncopied = "; print_map(copied);
    std::cout << "map1 = "; print_map(map1);

    std::map<std::string, int> moved(std::move(map1));  // (4) 移动构造函数
    std::cout << "\nmoved = "; print_map(moved);
    std::cout << "map1 = "; print_map(map1);

    const std::map<std::string, int> init {  // (5) initializer_list 构造函数
        {"this", 100},
        {"can", 100},
        {"be", 100},
        {"const", 100},
    };
    std::cout << "init = "; print_map(init);

    //2. 访问
    std::cout << map1["something"] << std::endl;

    //3. 容量
    std::cout << "empty: " << map1.empty() << std::endl;
    std::cout << "size: " << map1.size() << std::endl;
    std::cout << "max_size: " << map1.max_size() << std::endl;

    //4. 修改器
    iter.clear(); //清除元素    
    map1.emplace("bilibili", 2233); //原位构造函数
    map1.erase("something");
 

    //5. 查找
    auto search = map1.find("bilibili");
    std::cout << "find: " << search->second << std::endl;

    for(auto elemt: map1){
        std::cout << "[" << elemt.first << "]: " << elemt.second << std::endl;
    }

    /******************************multimap******************************/
    std::multimap<std::string, int> map2 = {
        {"a", 1},
        {"b", 2},
        {"a", 3},
        {"d", 4},
        {"a", 3},
        {"a", 3},
        {"a", 3},
        {"a", 3},
    };

    for(auto elemt: map2){
        std::cout << "[" << elemt.first << " : " << elemt.second << "]" << std::endl;
    }
    
    std::cout << map2.count("a") << std::endl; //计算有多少个key元素

    return 0;
}