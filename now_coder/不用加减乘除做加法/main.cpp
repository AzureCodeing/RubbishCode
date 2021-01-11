#include <iostream>

class Solution {
public:
    int Add(int num1, int num2)
    {
        int temp = 0;
        while(num2){
            temp = num1^num2;
            num2 = (num1&num2) << 1;
            num1 = temp;
        }
        return num1;
    }
};


int main(int argc, char *argv[])
{
    Solution num;
    std::cout << "加法计算结果: " << num.Add(12,22) << std::endl;
    return 0;
}