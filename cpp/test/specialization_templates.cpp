//模板特化
#include <iostream> 

template <typename T> 
struct temp {
    temp(){std::cout << "default" << std::endl;}
};

template<> struct temp<int>{
    temp(){std::cout << "special int" << std::endl;}
};

template<typename T> struct temp<T*>{
    temp(){std::cout << "special pointer" << std::endl;}
};

template<> struct temp<double>{
    temp(){std::cout << "special double" << std::endl;}
};

template<> struct temp<long>{
    temp(){std::cout << "special long" << std::endl;}
};

//函数模板
template<typename T, typename D>
struct madd {
    madd(){std::cout << "add default" << std::endl;}
};

//全特化版本
template<> struct madd<int, int>{
    madd(){std::cout << "all special template" << std::endl;}
};

//偏特化版本
template<typename T> struct madd<T,double>{
    madd(){std::cout << "special template - special" << std::endl;} //数量上的偏特化
};

template<typename T, typename D> struct madd<T*,D*>{
    madd(){std::cout << "part special template - point" << std::endl;} //范围上的偏特化
};


int main(int argc, char *argv[])
{
    temp<int> p1;
    temp<int*> p2;
    temp<double*> p3;
    temp<double> p4;
    temp<long> p5;

    madd<double, int> p7;
    madd<double*, int*> p8;
    madd<int, double> p9;

    return 0;
}