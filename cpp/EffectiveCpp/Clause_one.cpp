#include <iostream>
//尽量用const,enum,inline替换#define

#define CALL_WITH_MAX(a,b) ((a) > (b) ? (a) : (b))
#define ASPECT_RATIO_1 1.653 //替换
const double ASPECT_RATIO_2 = 1.653; //非替换



int main(int argc, char *argv[])
{
    double arr[10000];
    //1. 报错信息阅读性差,原因是你所使用的名称未进入记号表
    // int arr[2] = {1, ASPECT_RATIO}; //error: narrowing conversion of ‘1.653e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]
    //2. 因为#define 是编译器直接原样替换,当多次使用会导致代码体积变大

    int a = 2;
    int b = 3;
    int c = CALL_WITH_MAX(++a,b);
    std::cout << "a: " << a << "\tb: " << b << std::endl;

    return 0;
}
