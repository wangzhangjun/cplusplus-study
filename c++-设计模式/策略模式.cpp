#include <iostream>
#include <vector>
#include <string>
using namespace std;

//抽象武器，武器策略
class WeponStrategy{
    public:
        virtual void UseWeapon() = 0;
};

class Knife : public WeponStrategy{
    virtual void UseWeapon() {
        cout << "刀子。。" << endl;
    }
};
class AK47 : public WeponStrategy
{
    virtual void UseWeapon()
    {
        cout << "AK47。。" << endl;
    }
};

class Character{
    public:
        void setWepon(WeponStrategy *wepon)
        {
            this->pWepon = wepon;
        }
        void useWepon(){
            this->pWepon->UseWeapon();
        }
    public:
        WeponStrategy *pWepon;
};

void test()
{
    //创建角色
    Character *p = new Character;
 
    //武器策略
    WeponStrategy *knife = new Knife;
    WeponStrategy *ak = new AK47;

    p->setWepon(knife);
    p->useWepon();
    p->setWepon(ak);
    p->useWepon();
}

int main()
{
    test();
    return 0;
}