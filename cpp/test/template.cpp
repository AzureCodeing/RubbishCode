#include <iostream>


/*C 语言高级技巧 函数指针*/
typedef int(*func)(int);

int test1(int a)
{
    std::cout << "test1" << std::endl;
    return a;
}

int test2(int b)
{
    std::cout << "test2" << std::endl;
    return b;
}


//-----------------------func----------------------
int getOne(int a) {
    return 1;
}

struct getTwo {
    getTwo() {}
    int operator()(int a) {
        return 2;
    }
};

// 默认特化不实现
template < typename T >
class Function;

template < typename Ret, typename... Args >
class Function< Ret(Args...) > {
    //构造虚基类以存储任意可调用对象的指针
    struct callable_base {
        // 注释M 此处Args我们在参数后面加了&&, 这个地方比较关键.
        virtual Ret operator()(Args &&... a) = 0;   // line 1 **
        virtual struct callable_base *copy() const = 0;
        virtual ~callable_base(){};
    };
    struct callable_base *base;

    template < typename T >
    struct callable_derived : public callable_base {
        T f;
        callable_derived(T functor) : f(functor) {}
        Ret operator()(Args &&... a) {             // line 2  **
            return f(std::forward< Args >(a)...); //完美转发
        }

        struct callable_base *copy() const {
            return new callable_derived< T >(f);
        }
    };

public:
    template < typename T >
    Function(T functor) : base(new callable_derived< T >(functor)) {}
    Function() : base(nullptr) {}
    // 实际调用存储的函数
    Ret operator()(Args... arg) {
        return (*base)(std::forward< Args >(arg)...);
    }
    Function(const Function &f) {
        std::cout << "copy construct" << std::endl;
        base = f.base->copy();
    }
    Function &operator=(const Function &f) {
        std::cout << "assign construct" << std::endl;
        delete base;
        base = f.base->copy();
        return *this;
    }

    ~Function() {
        std::cout << "delete current base callable object" << std::endl;
        delete base;
    }
};




//-----------------
template<typename T> class myfunction; //默认模板类
template<typename R, typename A> class myfunction<R(A)>{
public:
    R operator()(A arg0) {
        std::cout << "myfunction" << std::endl;
        return {};
    }
};


int main(int argc, char *argv[])
{
    func fu = test1;
    fu(1);
    fu = (&test2);
    fu(2);

   class Function< int(int) > getNumber(getOne);
   std::cout << getNumber(3) << std::endl;
   class Function< int(int) > getNumber2(getTwo{});
   std::cout << getNumber2(2) << std::endl;
   class Function< int(int) > getNumber3 = getNumber2;
   getNumber3 = getNumber;

    class myfunction<int(int)> myfun;
    myfun(int(123));
    return 0;
}