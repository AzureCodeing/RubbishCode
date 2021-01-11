#include <iostream>
#include <vector>

using namespace std;

/*
* array = {1, 3, 5, 7,
           2, 4, 6, 8,
           5, 6, 7, 11,
           7, 9, 12, 13}
*/

class Solution {
public:
    /*方法一: 双层遍历 O(n^2)
    * 性能: 运行时间：14ms 占用内存：1376k
    */
    bool Find1(int target, vector<vector<int> > array) {
        if(array.empty()) return false;

        //c++11
        for(auto i : array){
            for(auto j : i)
                if(target == j)   return true;
        }

        // //先行后列
        // for(int i = 0; i < array.size(); i++){
        //     for(int j = 0; j < array[0].size(); j++){
        //         if(target == array[i][j])   return true;
        //     }
        // }

        return false;
    }

    /*  方法二： 利用排列规律查找 O(logn)
        性能: 运行时间：12ms 占用内存：1484k
    */
    bool Find2(int target, vector<vector<int> > array) {
        if(array.empty()) return false;

        int row = 0, col = array[0].size() - 1;
        while(row <= array.size()-1 && col >= 0 ){
            if(target < array[row][col]) col--;
            else if(target > array[row][col]) row++;
            if(target == array[row][col])  return true;
        }
        return false;
    }
};


int main(int argc, char *argv[])
{
    std::vector<std::vector<int> > input = {{1,3,5,7},
                                            {2,4,6,8},
                                            {5,6,7,11},
                                            {7,9,12,13}};

    int target = 9;
    Solution a;
    std::cout << "数组中是否包[" << target << "]: " << "方法一：　" << a.Find1(target, input);
    std::cout << "\t方法二: " << a.Find2(target, input) << std::endl;

    return 0;
}