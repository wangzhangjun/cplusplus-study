#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AbstractFruit {
    public:
        virtual void showName() = 0;
};

class Apple : public AbstractFruit{
    public:
        virtual void showName(){
            cout << "apple." << endl;
        }
};

class Banan : public AbstractFruit{
public:
    virtual void showName()
    {
        cout << "banan." << endl;
    }
};

class FruitFactory{
    public:
        static AbstractFruit * createFruit(string flag) {
            //不符合开闭原则
            if(flag == "apple") {
                return new Apple;
            }else if(flag == "bana"){
                return new Banan;
            }
        }
};

void test1()
{
    FruitFactory *factor = new FruitFactory;
    AbstractFruit *fruit = factor->createFruit("apple");
    fruit->showName();
}

int main()
{
    test1();
    return 0;
}