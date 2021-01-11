/*
    本程序用来计算大整数相减
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

//判断两个字符串谁大
bool mystrcmp(const std::string &input_a, const std::string &input_b)
{
    if(input_a.length() < input_b.length()) {
        return true;
    }else if(input_a.length() == input_b.length()){
        for(size_t i = input_a.length(); i >=0 ; i++){
            if((input_a[i] - '0') < (input_b[i] - '0'))
                return true;
        }
    }
    return false;
}


//大整数相减
std::string large_integer_sub(const std::string &input_a, const std::string &input_b)
{
    if(input_a.empty()) return input_b;
    if(input_b.empty()) return input_a;

    std::string rec;
    int borrow = 0;

    int length_a = input_a.length();
    int length_b = input_b.length();

    //由于在调用的时候已经做过判断，所以此时最长的长度应该就是input_a的长度
    for(int i = input_a.length(); i >= 0; i--){
        int num_a = --length_a >=0 ? input_a[length_a] - '0' : 0;
        int num_b = --length_b >=0 ? input_b[length_b] - '0' : 0;

        num_a -= borrow; //根据上一次计算结果借位

        if((num_a - num_b) < 0){
            borrow = 1; //借位
            rec = to_string((10+num_a-num_b)) + rec;
        }else if((num_a - num_b) > 0){
            borrow = 0; //不借位
            rec = to_string(num_a - num_b) + rec;
        }else{
            borrow = 0; //不借位
            rec = "0"+rec;
        }
    }
    return rec;
}


int main(int argc, char *argv[])
{
    std::string a = "123456789";
    std::string b = "987654321";

    string out;

    //这里确定到底是减谁，因为被减数一定要小于减数
    if(!mystrcmp(a,b)){
        out = "+" + large_integer_sub(a, b);
    }else{
        out = "-" + large_integer_sub(b, a);
    }

    std::cout << a << " - " << b << " = " << out << std::endl;

    return 0;
}