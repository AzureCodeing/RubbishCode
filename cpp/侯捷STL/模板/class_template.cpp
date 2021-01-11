#include <iostream>

//类模板
template<typename T>
class complex
{
public:
    complex(T r = 0, T i = 0): re(r), im(i)
    { }
    complex& operator+=(const complex&);
    T real() const {return re;}
    T imag() const {return im;}

private:
    T re, im;
};

int main(int argc, char *argv[])
{
    complex<double> c1(2.5, 1.5);
    complex<double> c2(2, 6);

    std::cout << "c1.imag: " << c1.imag() << std::endl;
    std::cout << "c2.real: " << c2.real() << std::endl;

    return 0;
}