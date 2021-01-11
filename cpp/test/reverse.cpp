#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//元素前后互换
std::vector<int> reverseArray1(const std::vector<int> &a)
{
    std::vector<int> output = a;
    //加减法
    // for(size_t i = 0; i < output.size()/2; i++){
    //     output[i] = output[i] + output[output.size() -1 - i];
    //     output[output.size() -1 - i] = output[i] - output[output.size() -1 - i];
    //     output[i] = output[i] - output[output.size() -1 - i];
    // }
    
    //乘除法
    // for(size_t i = 0; i < output.size()/2; i++){
    //     output[i] = output[i] * output[output.size() -1 - i];
    //     output[output.size() -1 - i] = output[i] / output[output.size() -1 - i];
    //     output[i] = output[i] / output[output.size() -1 - i];
    // }

    //三次异或
    for(size_t i = 0; i < output.size()/2; i++){
        output[i] ^= output[output.size() -1 - i];
        output[output.size() -1 - i] ^= output[i];
        output[i] ^= output[output.size() -1 - i];
    }

    return output;
}

vector<int> reverseArray2(vector<int> a) {
    vector<int> temp;
    for(auto ite = a.end() - 1; ite >= a.begin();ite--){
        temp.push_back(*ite);
    }
    return temp;
}

vector<int> reverseArray3(vector<int> a)
{
    return {a.rbegin(), a.rend()};
}

vector<int> reverseArray4(vector<int> a)
{
    reverse(a.begin(),a.end());
    return a;
}



int main(int argc, char *argv[])
{
    const std::vector<int> a = {1,2,3,4,5,6,7,8,9};
    std::vector<int> b;

    b = reverseArray2(a);

    std::cout << "颠倒前数组: ";
    for(auto vec1:a){
        std::cout << vec1 << " " ;
    }
    std::cout << std::endl;



    std::cout << "颠倒后数组: ";
    for(auto vec1:b){
        std::cout << vec1 << " " ;
    }
    std::cout << std::endl;
    return 0;
}