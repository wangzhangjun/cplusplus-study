#include <iostream>
#include <vector>
#include <string>

class AbstractCar{
    public:
        virtual void run() = 0;
        virtual ~AbstractCar() = 0;
};
AbstractCar::~AbstractCar(){}

class Dazhong : public AbstractCar
{
    public:
        virtual void run(){
            std::cout << "大众..." <<std::endl;
        }
        ~Dazhong(){}
};

class Tuolaji : public AbstractCar
{
    public:
        virtual void run()
        {
            std::cout << "拖拉机..." << std::endl;
        }
        ~Tuolaji(){}
};

//假设现在有个人想开车。那么你可以是用继承，person类继承Dazhong或者继承Tuolaji
//这种方式，最好使用组合

class Person
{
    public:
        void setCar(AbstractCar *car)
        {
            this->car = car;
        }
        void doFeng(){
            car->run();
        }
        ~Person(){
            if(car != nullptr)
            {
                std::cout << "delete car" << std::endl;
                delete car;
            }
                
        }
    private:
        AbstractCar *car;
};
void test()
{
    Person p;
    p.setCar(new Dazhong);
    p.doFeng();
}
int main()
{
    test();
    return 0;
}