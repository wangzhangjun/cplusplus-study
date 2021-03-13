#include <iostream>

//抽象类
class AbstractCaculator
{
    public:
        virtual int getResult() = 0;
        virtual ~AbstractCaculator() = 0;
};

AbstractCaculator::~AbstractCaculator(){}  //纯析构函数必须给出函数体

//加法计算器类
class plusCaculator : public AbstractCaculator
{
public:
    plusCaculator(int a, int b)
    {
        mA = a;
        mB = b;
    }
    virtual int getResult()
    {
        return mA + mB;
    }
    ~plusCaculator() {}

private:
    int mA;
    int mB;
};
//减法计算器类
class minuteCaculator : public AbstractCaculator {
public:
    minuteCaculator(int a, int b)
    {
        mA = a;
        mB = b;
    }
    virtual int getResult()
    {
        return mA - mB;
    }
    ~minuteCaculator(){}
private:
    int mA;
    int mB;
};

//当你再需要加一个运算的时候，不会修改原来的代码，而是通过添加代码的方式来

void test()
{
    AbstractCaculator * cac = new plusCaculator(1,2);
    std::cout << cac->getResult() << std::endl;
    delete cac;

    AbstractCaculator *cac1 = new minuteCaculator(10,5);
    std::cout << cac1->getResult() << std::endl;
    delete cac1;
}
int main()
{
    test();
    return 0;
}