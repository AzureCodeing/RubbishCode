#include <iostream>

class Solution {
public:
    //方法一: 递归
    int Fibonacci1(int n) {
        if(n == 0) return 0; //设置递归退出条件
        if(n == 1) return 1;
        return (Fibonacci1(n-1)+Fibonacci1(n-2));
    }
    //方法二: 记录上一次值 1 1 2 3 5
    int Fibonacci2(int n) {
        if(n == 0) return 0; //排除前两个特殊情况
        if(n == 1) return 0; 
        int temp = 0, a = 0, b = 1;
        for(int i = 2; i <= n ; i++){
            temp = a + b;
            a = b;
            b = temp;
        }
        return temp;
    }

};

int main(int argc, char *argv[])
{
    Solution Fibonacci;
    
    std::cout << Fibonacci.Fibonacci1(10) << std::endl; 
    std::cout << Fibonacci.Fibonacci2(10) << std::endl; 
    return 0;
}