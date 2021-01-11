#include <iostream>

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        int i = 1;
        int left = 0, right = 0, current = 0;
        while((n/i) != 0){
            current = (n / i) % 10; //当前位
            left = n/ (i*10); //当前位左面
            right = n - (n / i)*i; //当前位右面
            if(current == 0){ //左边值*当前位
                count += left * i; 
            }else if(current == 1){ //左边值*当前位 + (右边值+1)
                count += (left * i) + (right + 1);
            }else{//(左边值+1)*当前位
                count += (left+1)*i;
            }
            i *= 10;
        }
        return count;
    }
};

int main(int argc, char *argv[])
{
    int num = 1234556;
    Solution numbers;

    std::cout << num << " 中包含 "<< numbers.NumberOf1Between1AndN_Solution(num) << "个1" << std::endl;

    return 0;
}