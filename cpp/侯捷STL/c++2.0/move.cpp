#include <iostream>
class move_test
{
public:
    /*Big_Five*/
    move_test(){}; //构造函数
    move_test(const move_test& p){std::cout << "拷贝构造" << std::endl;}; //拷贝构造
    move_test& operator=(const move_test& p){std::cout << "拷贝赋值" << std::endl;}; //拷贝赋值
    move_test(const move_test&& p){std::cout << "搬移构造" << std::endl;}; //搬移赋值
    move_test& operator=(const move_test&& p){std::cout << "搬移赋值" << std::endl;}; //搬移赋值

    ~move_test(){}; //析构函数
    void fun(const int&& i){std::cout << "普通搬移函数" << std::endl;};
    void fun(const int& i){std::cout << "普通成员函数" << std::endl;};
};

int main(int argc, char *argv[])
{
    move_test p1, p3, p5;
    move_test p2(p1); //拷贝构造
    p3 = p1; //拷贝赋值
    move_test p4(std::move(p2)); //搬移构造
    p5 = std::move(p1); //搬移赋值

    int a = 1;
    p1.fun(a);
    p1.fun(std::move(1));
    return 0;
}