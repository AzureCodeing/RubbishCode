#include <iostream>
#include <cmath>

class Solution {
/* number 1     1
    number 2     2
    number 3     4
    number 4     8
    number n     2n(n-1)
    f(n) = f(n-1) + f(n-2)~f(1)
    f(n-1) = f(n-2)~f(1)
    f(n) = 2f(n-1)
*/
public:
    /*
    *　方法一:迭代法
       性能: 运行时间：3ms 占用内存：484k
    * */
    int jumpFloorII1(int number) {
       if(number == 0) return 0;
       if(number == 1) return 1;
        int last = 1;
        int now = 0;

        for(int i = 2; i < number + 1; i++){
            now = 2*last;
            last = now;
        }
        return now;
    }

    /*
        方法二: 公式法
        性能: 运行时间：5ms  占用内存：376k
    */
    int jumpFloorII2(int number) {
        //公式 2^(n-1)
        return std::pow(2, number-1);
    }

};


int main(int argc, char *argv[])
{
    Solution t;
    int n = 4;
    std::cout << "台阶数: " << n << "\t方法二: " << t.jumpFloorII2(n) << "\t方法一: " << t.jumpFloorII1(n) <<std::endl;
    return 0;
}