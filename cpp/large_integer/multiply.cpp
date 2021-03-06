/*
    本程序用来计算大整数相加
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

//大数相加
std::string large_integer_add(const std::string &input_a, const std::string &input_b)
{
    if(input_a.empty()) return input_b;
    if(input_b.empty()) return input_a;

    std::string rec;

    int a_length = input_a.length();
    int b_length = input_b.length();

    //计算两个相加的数谁更长
    std::size_t length = (a_length > b_length ? a_length : b_length);

    int carr = 0;


    for(int i = length - 1; i >= 0; i--){
        int num_a =  --a_length >= 0 ? input_a[a_length] - '0' : 0;
        int num_b =  --b_length >= 0 ? input_b[b_length] - '0' : 0; 
        carr += num_a + num_b;
        rec = to_string(carr % 10)+rec;
        carr /= 10;
    }
    //处理最后一个进位
    return carr > 0?(to_string(carr % 10)+rec): rec;
}



//单个相乘
std::string single_mulitiply(const std::string &input_a, const char &input_b)
{
    std::string rec = "";
    int carr = 0;
    
    int num_b = input_b - '0';
    for(int i = input_a.length() - 1 ; i >= 0; i--){
        int num_a =  input_a[i] - '0';
        carr +=  num_a * num_b;
        rec = to_string(carr % 10) + rec;
        carr /= 10;
    }

    return carr > 0?(to_string(carr % 10)+rec): rec;
}


//大数相乘
std::string large_integer_mulitiply(const std::string &input_a, const std::string &input_b)
{
    std::string rec = "0";
    std::string temp;
    for(int i = input_b.length() - 1; i >= 0; i--){
        temp = single_mulitiply(input_a, input_b[i]);
        for(int j = 0; j < (input_b.length() - 1) - i ; j++) temp += "0";
        std::cout <<"rec = " << rec << " \t temp= " << temp << std::endl;
        rec = large_integer_add(rec,temp);
    }

    return rec;
}

int main(int argc, char *argv[])
{
    std::string a = "2898";
    std::string b = "2898";
    std::cout << a << " * " << b << " =" <<large_integer_mulitiply(a, b) << std::endl;
    return 0;
}