#include <iostream>
#include <vector>
#include <string>

class AbstractBuilding {
    public:
        virtual void sale() = 0;
        virtual std::string getQulity() = 0;
        virtual ~AbstractBuilding() = 0;
};

AbstractBuilding::~AbstractBuilding(){}

class buildingA : public AbstractBuilding {
    public:
        buildingA(){
            mQulity = "high";
        }
        virtual void sale(){
            std::cout << "楼盘A" << mQulity << std::endl;
        }
        virtual std::string getQulity(){
            return mQulity;
        }
        ~buildingA(){}
        std::string mQulity;
};

class buildingB : public AbstractBuilding
{
public:
    buildingB()
    {
        mQulity = "LOW";
    }
    virtual void sale()
    {
        std::cout << "楼盘B" << mQulity << std::endl;
    }
    virtual std::string getQulity()
    {
        return mQulity;
    }
    ~buildingB() {}
    std::string mQulity;
};

//客户端
void test(){
    //这种方式是直接和类打交道，所以抽象一个中间类
    buildingA *ba = new buildingA;
    if (ba->mQulity == "high"){
        ba->sale();
    }
}

//中介类
//需要对外提供接口
class Mediator{
    public:
        Mediator(){
            AbstractBuilding *building = new buildingA;
            vBuilding.push_back(building);
            AbstractBuilding *building1 = new buildingB;
            vBuilding.push_back(building1);
        }
        AbstractBuilding *findMyBuilding(std::string quality) {
            for (auto it = vBuilding.begin(); it != vBuilding.end(); ++it)
            {
                if ((*it)->getQulity() == quality)
                {
                    return *it;
                }
            }
            return nullptr;
        }
        ~Mediator(){
            for (auto it = vBuilding.begin(); it != vBuilding.end(); ++it) {
                if(*it != nullptr){
                    delete *it;
                }
            }
        }
    public:
        std::vector<AbstractBuilding *> vBuilding;
};

void test1()
{
    Mediator *med = new Mediator;
    AbstractBuilding *build = med->findMyBuilding("high");
    if(build != nullptr) {
        build->sale();
    }else{
        std::cout << "没有找到！" << std::endl;
    }
}

int main()
{
    // test();
    test1();
    return 0;
}