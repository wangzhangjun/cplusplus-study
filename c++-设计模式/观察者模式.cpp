#include <iostream>
#include <list>

class abstractHero{
    public:
        virtual void update()=0;
};

class HeroA : public abstractHero{
public:
    HeroA(){
        std::cout << "英雄A在打Boss..." << std::endl;
    }
    virtual void update(){
        std::cout << "英雄A停止Boss..." << std::endl;
    }
};

class HeroB : public abstractHero
{
public:
    HeroB()
    {
        std::cout << "英雄B在打Boss..." << std::endl;
    }
    virtual void update()
    {
        std::cout << "英雄B停止Boss..." << std::endl;
    }
};

class HeroC : public abstractHero
{
public:
    HeroC()
    {
        std::cout << "英雄C在打Boss..." << std::endl;
    }
    virtual void update()
    {
        std::cout << "英雄C停止Boss..." << std::endl;
    }
};

class HeroD : public abstractHero
{
public:
    HeroD()
    {
        std::cout << "英雄D在打Boss..." << std::endl;
    }
    virtual void update()
    {
        std::cout << "英雄D停止Boss..." << std::endl;
    }
};

//观察目标
class abstractBoss {
    public:
        virtual void addHero(abstractHero *hero) = 0;
        virtual void deleteHero(abstractHero *hero) = 0;
        virtual void notiy() = 0;
};

class BossA : public abstractBoss {
    public:
        virtual void addHero(abstractHero *hero){
            pHeroList.push_back(hero);
        }
        virtual void deleteHero(abstractHero *hero){
            pHeroList.remove(hero);
        }
        virtual void notiy(){
            for(auto it  = pHeroList.begin(); it != pHeroList.end(); ++it) {
                (*it)->update();
            }
        }
    private:
        std::list<abstractHero *> pHeroList;
};
int main()
{
    //创建观察者
    abstractHero *a = new HeroA();
    abstractHero *b = new HeroB();
    abstractHero *c = new HeroC();
    abstractHero *d = new HeroD();

    //创建观察者目标
    abstractBoss *boss = new BossA();
    boss->addHero(a);
    boss->addHero(b);
    boss->addHero(c);
    boss->addHero(d);

    std::cout << "c阵亡。。。" << std::endl;
    boss->deleteHero(c);
    boss->notiy(); 
    return 0;
}