#include <iostream>
#include <string>

class Solution {
public:
	void replaceSpace1(char *str,int length) {
        //计算插入字符后的字符串长度
        size_t new_length = 0;
        for(int i = 0; i < length; i++){
            new_length += 1;
            if(str[i] == ' ') new_length += 2;
        }

        size_t old_length = length;
        
        while(old_length >= 0 && new_length > old_length){
            if(str[old_length] == ' '){
                str[new_length--] = '0';
                str[new_length--] = '2';
                str[new_length--] = '%';
            }
            else{
                str[new_length--] = str[old_length];
            }
            old_length--;
        }
	}
};


int main(int argc, char *argv[])
{
    std::string str = "We Are Happy";
    Solution a;
    //const_cast<type>　强制去除const
    a.replaceSpace1(const_cast<char*>(str.c_str()), str.length());

    for(int i = 0; i < 16; i++){
        std::cout << str[i] ;
    }

    std::cout << std::endl;

    return 0;
}