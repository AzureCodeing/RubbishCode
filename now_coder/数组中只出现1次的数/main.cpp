#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //数组中只有两个数字出现过一次
    void FindNumsAppearOnce0(vector<int> array,int* num1,int *num2) 
    {
        int sum = 0;
        int index;

        for(auto elemt: array) sum ^= elemt; //异或完成之后结果就是两个不同数字进行异或

        for(int index = 0; index < (sizeof(int) * 8); index++){
            if(sum & (1 << index) != 0) break; //以二进制的形式从右到左找到第一个为1的位．
        }

        for(int i = 0; i < array.size(); i++){
            if((array[i] & (1 << index)) != 0)  *num1 ^= array[i]; //根据上面的结果以找的的位为分割，在分别异或就可以得到数组中两个不同的数
            else *num2 ^= array[i];
        }
    }

    //数组中只出现过一次的数字
    void FindNumsAppearOnce1(vector<int> array,int *num) 
    {
        for(auto elemt: array) *num ^= elemt;
    }

    
    //数组中一个数只出现过一次，其他数都出现过3次
    void FindNumsAppearOnce2(vector<int> array, int *num)
    {
        std::vector<int> vec_temp(sizeof(int)*8, 0);
        for(int i = 0; i < array.size(); i++){
            for(int j = 0; j < (sizeof(int) * 8); j++){
                vec_temp[j] += ((array[i] >> j) & 1);   //二进制中计算32位中每一位的和
            }
        }

        for(int i = 0; i < (sizeof(int)*8); i++){
            if(vec_temp[i] % 3 != 0) *num |= (1 << i); //挑出特殊
        }

    }
};


int main(int argc, char *argv[])
{
    std::vector<int> input0 = {1,1,2,2,3,3,4,5,5,6,6,7,8,8}; // 4和7只出现过一次其余2次
    std::vector<int> input1 = {1,1,2,2,3,4,4,5,5,6,6,7,7,8,8}; //3只出现过一次其余2次
    std::vector<int> input2 = {1,1,1,2,2,2,3,3,3,4,5,5,5,6,6,6,7,7,7}; //4只出现一次其余3次

    Solution find_num;

    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;

    find_num.FindNumsAppearOnce0(input0, &num1, &num2);    
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;

    find_num.FindNumsAppearOnce1(input1, &num3);
    std::cout << "num3: " << num3 << std::endl;

    find_num.FindNumsAppearOnce2(input2, &num4);
    std::cout << "num4: " << num4 << std::endl;
    return 0;
}