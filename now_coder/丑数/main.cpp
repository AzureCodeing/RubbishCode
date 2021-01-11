#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7) return index;
        int p2 = 0, p3 = 0, p5 = 0, numbers = 1;
        std::vector<int> array;
        array.push_back(numbers);
        while(array.size() < index){
            numbers = std::min(array[p2] * 2, std::min(array[p3] * 3, array[p5] * 5));
            if(array[p2] * 2 == numbers) p2++;
            if(array[p3] * 3 == numbers) p3++;
            if(array[p5] * 5 == numbers) p5++;
            array.push_back(numbers);
        }
        return numbers;
    }
};

int main(int argc, char *argv[])
{
    int n = 11;
    Solution UglyNumber;

    std::cout << "第 "  << n << "个丑数为: " << UglyNumber.GetUglyNumber_Solution(n) << std::endl;
    return 0;
}