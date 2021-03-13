#include <iostream>
#include <vector>
#include <string>

//底层模块
class BankWorker{
    public:
        void SaveService(){
            std::cout << "存款。。。" << std::endl;
        }
        void payService(){
            std::cout << "支付。。。" << std::endl;
        }
        void transService(){
            std::cout << "转账。。。" << std::endl;
        }
};

//中间模块层
void doSaveBusiness(BankWorker *worker)
{
    worker->SaveService();
}
void doPayBusiness(BankWorker *worker)
{
    worker->payService();
}
void dotransBusiness(BankWorker *worker)
{
    worker->transService();
}

//高层业务
void test()
{
    BankWorker bankworker = new BankWorker;
    doSaveBusiness(bankworker);
    doPayBusiness(bankworker);
    dotransBusiness(bankworker);
}


//依赖倒置
class AbstractWorker{
    public:
        virtual void doBusiness() = 0;
};

class saveBankWorker : public AbstractWorker{
public:
    virtual void doBusiness(){
        std::cout << "存款。。。" << std::endl;
    }
};

class payBankWorker : public AbstractWorker{
public:
    virtual void doBusiness()
    {
        std::cout << "支付。。。" << std::endl;
    }
};

class transBankWorker : public AbstractWorker{
public:
    virtual void doBusiness()
    {
        std::cout << "转账。。。" << std::endl;
    }
};

//中层模块（依赖一个抽象层）
void doNewBusiness(AbstractWorker *worker) {
    worker->doBusiness();  
}

//高层
void test1(){
    AbstractWorker *workter  = new transBankWorker;
    doNewBusiness(workter);
}

int main()
{
    test1();
    return 0;
}