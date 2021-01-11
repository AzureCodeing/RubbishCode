#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    //1. 排序统计 时间复杂度 O(nlogn) 空间复杂度O(1)
    int MoreThanHalfNum_Solution1(vector<int> numbers) {
        sort(numbers.begin(), numbers.end()); //排序算法
        int sum = 0;        
        for(auto num:numbers){//计算中间数个数是否大于整个数组的一半
            if(numbers[numbers.size()/2] == num){
                sum++;    
            }
        }
        return (sum > numbers.size()/2 ? numbers[numbers.size()/2]:0);
    }
    
    //2. hash_map统计 时间复杂度 O(nlogn) 空间复杂度O(n)
    int MoreThanHalfNum_Solution2(vector<int> numbers) {
        map<int, int> temp_map;
        for(auto num: numbers){
            temp_map[num]++;
        }
        for(int i = 0; i < numbers.size(); i++){
            if(temp_map[numbers[i]] > numbers.size()/2){
                return numbers[i];
            }
        }
        return 0;
    }
    
    //3. 重复元素计数法　时间复杂度O(n) 空间复杂度O(1)
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int numberCount = 0;
        int last_number = 0;
        for(auto num: numbers){
            if(numberCount == 0){
                last_number = num;
                numberCount = 1;
            }else{
                if(num == last_number) numberCount++;
                else numberCount--;
            }
        }
        if(numberCount == 0) return 0;
        else{
            numberCount = 0;
            for(auto num: numbers){
                if(last_number == num) numberCount++;
            }
        }
        return numberCount > (numbers.size()>>1) ? last_number: 0;
    }



};

int main(int argc, char *argv[])
{
    Solution sol;

    std::vector<int> vec1 = {1,2,3,2,2,2,5,4,2,11,33};

    std::cout << "超过数组一半的元素是: " << sol.MoreThanHalfNum_Solution3(vec1) << std::endl;

    return 0;
}