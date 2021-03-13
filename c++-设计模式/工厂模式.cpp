#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AbstractFruit
{
public:
    virtual void showName() = 0;
};

class Apple : public AbstractFruit
{
public:
    virtual void showName()
    {
        cout << "apple." << endl;
    }
};

class Banan : public AbstractFruit
{
public:
    virtual void showName()
    {
        cout << "banan." << endl;
    }
};

//抽象工厂
class AbstractFruitFactory{
    public:
        virtual AbstractFruit* createFruit() = 0;
};
//苹果工厂
class AppleFactory : public AbstractFruitFactory{
    public:
        virtual AbstractFruit* createFruit(){
            return new Apple;
        }
};
//香蕉工厂
class BananFactory : public AbstractFruitFactory {
    public:
        virtual AbstractFruit * createFruit(){
            return new Banan;
        }
};
void test1()
{
    AbstractFruitFactory * factory = new AppleFactory;
    AbstractFruit *fruit = factory->createFruit();
    fruit->showName();
}

int main()
{
    test1();
    return 0;
}