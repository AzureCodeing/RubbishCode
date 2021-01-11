/*
    本程序用来计算大整数相加
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

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

    for(int i = length; i >= 0; i--){
        int num_a =  --a_length >= 0 ? input_a[a_length] - '0' : 0;
        int num_b =  --b_length >= 0 ? input_b[b_length] - '0' : 0; 
        carr += num_a + num_b;
        rec = to_string(carr % 10)+rec;
        carr /= 10;
    }
    return carr > 0?(to_string(carr % 10)+rec): rec;
}



int main(int argc, char *argv[])
{
    std::string a = "2222";
    std::string b = "2220";
    std::cout <<large_integer_add(a, b) << std::endl;
    return 0;
}