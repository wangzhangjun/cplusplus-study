#include <iostream>
#include <vector>
#include <string>

using namespace std;

//苹果
class AbstractApple{
    public:
        virtual void showName() = 0;
}
class chinaApple : public AbstractApple{
    public:
        virtual void showName(){
            cout << "china apple" << endl;
        }
};
class usaApple : public AbstractApple{
    public:
        virtual void showName(){
            cout << "usa apple" << endl;
        }
};
class jpanApple : public AbstractApple{
    public:
        virtual void showName(){
            cout << "jpan apple" << endl;
        }
};

//香蕉
class AbstractBan{
    public:
        virtual void showName() = 0;
};
class chinaBan : public AbstractBan{
public:
    virtual void showName(){
        cout << "china bana" << endl;
    }
};
class usaBan : public AbstractBan
{
public:
    virtual void showName()
    {
        cout << "usa bana" << endl;
    }
};
class jpanBan : public AbstractBan
{
public:
    virtual void showName()
    {
        cout << "jpan bana" << endl;
    }
};

//抽象工厂 针对产品族
class AbstractFactory{
    public:
        virtual createApple() = 0;
        virtual createBana() = 0;
};
//中国工厂
class ChinaFactory : public AbstractFactory {
public:
    virtual createApple()
    {
        return new chinaApple;
    }
    virtual createBana()
    {
        return new chinaBan;
    }
}
//usa工厂
class UsaFactory : public AbstractFactory{
public:
    virtual createApple()
    {
        return new usaApple;
    }
    virtual createBana()
    {
        return new usaBan;
    }
};
//jpan工厂
class JpanFactory : public AbstractFactory
{
public:
    virtual createApple()
    {
        return new jpanApple;
    }
    virtual createBana()
    {
        return new jpanBan;
    }
};

void test()
{
    AbstractFactory *factory = NULL;
    AbstractApple *apple = nullptr;
    AbstractBan *ban = nullptr;

    factory = new ChinaFactory;
    apple = factory->createApple();
    ban = factory->createBana();

}
int main()
{
    test();
    return 0;
}