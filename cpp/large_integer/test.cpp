#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_VALUE = 1;
const int MAX_VALUE = 20;

//随机数
std::string string_num_random()
{
    std::string output;

    int number = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

    for(int i = 0; i < number; i++){
          output += ('0' + (rand()%9));
    }

    return output;
}

//规范化
std::string Normalization(const std::string &input)
{
    string output = input;
    int num = 0;
    for(int i = 0; i < output.length()-1; i++){
        if(output[i] == '0') num++;
        else{
            break;
        }
    }
    if(num != 0) output.erase(0, num);

    return output;
}

/***********************加**************************/
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


/***********************减***************************/

//判断两个字符串谁大
bool mystrcmp(const std::string &input_a, const std::string &input_b)
{
    if(input_a.length() < input_b.length()) {
        return true;
    }else if(input_a.length() == input_b.length()){
        for(size_t i = input_a.length(); i <= 0; i++){
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


/***********************乘***********************/
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


std::string large_integer_mulitiply(const std::string &input_a, const std::string &input_b)
{
    std::string rec = "0";
    std::string temp;
    for(int i = input_b.length() - 1; i >= 0; i--){
        temp = single_mulitiply(input_a, input_b[i]);
        for(int j = 0; j < (input_b.length() - 1) - i ; j++) temp += "0";
        rec = large_integer_add(rec,temp);
    }

    return rec;
}




int main(int argc, char *argv[])
{
    unsigned seed;
    seed = time(0);
    srand(seed);

    std::string a = Normalization(string_num_random());
    std::string b = Normalization(string_num_random());

    std::cout << "a = " << a << "\t b = " << b << std::endl;

    string sub;
    if(!mystrcmp(a,b)){
        sub = Normalization(large_integer_sub(a, b));
    }else{
        sub = "-" + Normalization(large_integer_sub(b, a));
    }

    std::cout << "大数据加: " << Normalization(large_integer_add(a,b)) << "\t 正确答案: " << (stoll(a) + stoll(b)) << std::endl;

    std::cout << "大数据减: " << sub << "\t 正确答案: " << (stoll(a) - stoll(b)) << std::endl;

    std::cout << "大数据乘: " << Normalization(large_integer_mulitiply(a,b)) << "\t 正确答案: " << (stoll(a) * stoll(b)) << std::endl;

    string temp = "00517";
    std::cout << "temp: " << __LONG_LONG_MAX__ << std::endl;

    return 0;
}