#include <iostream>

class Solution {
public:
    //1: 递归法
    int jumpFloor1(int number) {
        if(number <= 0) return 0;
        if(number == 1) return 1;
        if(number == 2) return 2;
        return jumpFloor1(number - 1)+jumpFloor1(number - 2);
    }
    
    //2: 记录值
    int jumpFloor2(int number) {
        if(number < 1) return 0;
        if(number == 1) return 1;
        if(number == 2) return 2;

        int a = 1, b = 2, temp = 0;
        for(int i = 3; i <= number; i++){
            temp = b + a;
            a =  b;
            b = temp;
        }
        return temp;
    }
};

int main(int argc, char *argv[])
{
    Solution jump;

    std::cout << "共有跳法: " <<  jump.jumpFloor1(10) << std::endl;

    std::cout << "共有跳法: " <<  jump.jumpFloor2(10) << std::endl;
    return 0;
}