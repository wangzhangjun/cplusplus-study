#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DrinkTemplate{
    public:
        virtual void boilWater() = 0; //煮水
        virtual void Brew() = 0; //冲泡
        virtual void PourInCup() = 0; //倒入杯子
        virtual void AddSomething() = 0; //加入辅料
        void Make(){
            this->boilWater();
            this->Brew();
            this->PourInCup();
            this->AddSomething();
        }
};

//咖啡
class Coffe : public DrinkTemplate{
    public:
        virtual void boilWater(){
            cout << "煮山泉水。。。" << endl;
        }
        virtual void Brew(){
            cout << "coffe 泡。。。" << endl;
        }
        virtual void PourInCup(){
            cout << "倒入杯子。。。" << endl;
        }
        virtual void AddSomething(){
            cout << "加糖。。。" << endl;
        }
};

//泡茶
class Tea: public DrinkTemplate{
public:
    virtual void boilWater()
    {
        cout << "煮自来水。。。" << endl;
    }
    virtual void Brew()
    {
        cout << "铁观音泡。。。" << endl;
    }
    virtual void PourInCup()
    {
        cout << "茶水倒入杯子。。。" << endl;
    }
    virtual void AddSomething()
    {
        cout << "加醋。。。" << endl;
    }
};
void test()
{
    Tea * tea = new Tea;
    tea->Make();

    cout << "================" << endl;
    
    DrinkTemplate *coff = new Coffe;
    coff->Make();
}

int main()
{
    test();
    return 0;
}