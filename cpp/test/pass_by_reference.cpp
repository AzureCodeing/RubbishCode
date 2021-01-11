#include <iostream>

class TextBlock{
public:
TextBlock();
    // const char &operator[](std::size_t position) const
    // {
    //     std::cout << "const operator" << std::endl;
    //     return text[position];
    // }

    char &operator[](std::size_t position)
    {
        std::cout << "non-const operator" << std::endl;
        return text[position];
    }
private:
    std::string text;
};


TextBlock::TextBlock()
{
    text = "Hello World!!";
}

int main(int argc, char *argv[])
{
    TextBlock a;    
    const TextBlock b;


    std::cout<< "a: " << a[0] << std::endl;

    std::cout << "b: " << b[0] << std::endl;


    return 0;
}