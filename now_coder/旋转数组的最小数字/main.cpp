#include <iostream>
#include <vector>
#include <algorithm> //for min_element

using namespace std;

class Solution {
public:
    //循环便利最小值 时间复杂度O(n)
    int minNumberInRotateArray1(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        int min = INT32_MAX;
        for(auto n: rotateArray){
            if(min > n) min = n;
        }
        return min;
    }

    //二分查找
    int minNumberInRotateArray2(vector<int> rotateArray) {
        int front = 0, middle = 0, back = rotateArray.size() - 1;
        while(front <= back){
            middle = (front + back) >>1; //右移一位代表整除２
            if(rotateArray[middle] < rotateArray[middle - 1]){ //如果中间的数字小于前面的数字则为最小值
                return rotateArray[middle];
            }else if(rotateArray[middle] < rotateArray[front]){
                 back = middle - 1;
            }else{
                front = middle + 1;
            }
        }
    }

    //库函数
    int minNumberInRotateArray3(vector<int> rotateArray) {
    auto ite = min_element(rotateArray.begin(),rotateArray.end());
    return *ite;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> array={5,6,7,2};

    Solution a;

    std::cout << "方法一旋转数组最小元素: " << a.minNumberInRotateArray1(array) << std::endl;
    std::cout << "方法二旋转数组最小元素: " << a.minNumberInRotateArray2(array) << std::endl;

    return 0;
}