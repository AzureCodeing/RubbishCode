#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //冒泡排序 时间复杂度O(n*Longn) 空间复杂度O(1)
    void reOrderArray1(vector<int> &array) {
        for(int i = 0; i < array.size(); i++){
            for(int j = 0; j < array.size() - i; j++){
                if(array[j] % 2 == 0 && array[j + 1] % 2== 1){
                    int temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    //申请临时数组 时间复杂度O(n) 空间复杂度O(n)
    void reOrderArray2(vector<int> &array) {
        std::vector<int> temp;
        //装奇数
        for(auto n : array){
            if(n % 2 == 1) temp.push_back(n);
        }
        //装偶数
        for(auto n : array){
            if(n % 2 == 0) temp.push_back(n);
        }
        array = temp;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> array1 = {1,2,3,4,5,6,7,8,9};
    std::vector<int> array2 = {1,2,3,4,5,6,7,8,9};
    Solution a;

    a.reOrderArray1(array1);
    a.reOrderArray2(array2);

    std::cout << "array1= ";
    for(auto num: array1) std::cout << num;
    std::cout << std::endl;

    std::cout << "array2= ";
    for(auto num: array2) std::cout << num;
    std::cout << std::endl;

    return 0;
}