#include <iostream>

template<typename Function, typename... Args>
typename std::result_of<Function(Args...)>::type func(Function&& fun, Args&&... arg){
    std::cout << "返回值类型推导: \t";
    return fun(arg...);
}


int f1(int a, int b){
    return a+b;
}

int f2(){
    return 20;
}

void f3()
{
    std::cout << "f3 running" << std::endl;
}

int main(int argc, char*argv[])
{
   std::cout <<  func(f1, int(1), int(2)) << std::endl;
   std::cout <<  func(f2) << std::endl;
   func(f3);
   std::cout <<  func([](std::string a)->std::string{return "hello"+a;}, "world") << std::endl;

    return 0;
}