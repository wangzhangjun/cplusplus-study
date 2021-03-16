#include <iostream>
using namespace std;

//抽象英雄
class AbstractHero{
    public:
        int mHp;
        int mMp;
        int mAt;
        int mDf;
        virtual void showStats() = 0;
};

//具体英雄
class HeroA : public AbstractHero{
    public:
        HeroA(){
            mHp = 0;
            mMp = 0;
            mAt = 0;
            mDf = 0;
        } 
        virtual void showStats()
        {
            cout << "血量：" << mHp << endl;
            cout << "魔法：" << mMp << endl;
            cout << "攻击：" << mAt << endl;
            cout << "防御：" << mDf << endl;
        }
};

//给英雄穿衣服
//把英雄放到一个装饰器里面，然后变成一个新的英雄
//为什么继承AbstractHero，因为穿了衣服还是个英雄
class AbstractEquiment : public AbstractHero{
    public:
        AbstractEquiment(AbstractHero *hero)
        {
            this->phero = hero;
        }
        virtual void showStats(){

        }
    public:
        AbstractHero *phero;
};

//穿狂徒
class KuangtuEquement : public AbstractEquiment{
    public:
        KuangtuEquement(AbstractHero *hero) : AbstractEquiment(hero){}
        virtual void showStats()
        {
            addKuangtu();
            cout<< "血量：" << mHp << endl;
            cout << "魔法：" << mMp << endl;
            cout << "攻击：" << mAt << endl;
            cout << "防御：" << mDf << endl;
        }
        void addKuangtu(){
            cout <<  "穿狂徒"<< endl;
            this->mHp = this->phero->mHp;
            this->mMp = this->phero->mMp;
            this->mAt = this->phero->mAt;
            this->mDf = this->phero->mDf + 30;
        }
};

//无尽之刃
class wujin : public AbstractEquiment{
public:
    wujin(AbstractHero *hero) : AbstractEquiment(hero) {}
    virtual void showStats()
    {
        addwujin();
        cout << "血量：" << mHp << endl;
        cout << "魔法：" << mMp << endl;
        cout << "攻击：" << mAt << endl;
        cout << "防御：" << mDf << endl;
    }
    void addwujin()
    {
        cout << "穿无尽..." << endl;
        this->mHp = this->phero->mHp;
        this->mMp = this->phero->mMp;
        this->mAt = this->phero->mAt + 30;
        this->mDf = this->phero->mDf;
    }
};

void test()
{
    AbstractHero *a = new HeroA;
    a->showStats();

    //穿装备
    a = new KuangtuEquement(a);
    a->showStats();

    a = new wujin(a);
    a->showStats();


}
int main()
{
    test();
    return 0;
}