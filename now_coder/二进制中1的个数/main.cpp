#include <iostream>

class Solution {
public:
    int  NumberOf1(int n) {
        int sum = 0;
        while(n){
            sum++;
            n =(n-1)&n;
        }
        return sum;
    }
};


int main(int argc, char *argv[])
{
    Solution number;

    std::cout << "number: " << number.NumberOf1(4) << std::endl;

    return 0;
}