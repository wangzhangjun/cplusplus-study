#include <iostream>
#include "brass.h"

Brass::Brass(const std::string &s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if(amt < 0){
        std::cout << "deposit is cancelled" << std::endl;
    }
}

void Brass::Withdraw(double amt)
{
    if(amt < 0){
        std::cout << "withdraw is cancelled" << std::endl;
    }else if(amt <= balance){
        balance -= amt;
    }else{
        std::cout << "withdraw  cancelled" << std::endl;
    }
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    std::cout << "Brass::ViewAcct()" << std::endl;
}

void Brass::Withdraw(double amt) const
{
    std::cout << "Brass::Withdraw()" << std::endl;
}


//记住，子类无法直接访问父类的私有成员数据，必须使用父类的公有方法
//采用成员初始化列表来实现
BlassPlus::BlassPlus(const std::string &s, long an, double bal, double ml, double r)
    : Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BlassPlus::BlassPlus(const Brass &ba, double ml, double r) : Brass(ba)  //另一种构造
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BlassPlus::ViewAcct() const
{
    std::cout << "BlassPlus::ViewAcct()" << std::endl;
}

void BlassPlus::Withdraw(double amt) const
{
    double bal = Balance(); //这里可以使用父类的Balance()函数来确定结余。
    //但是比如要使用父类的WithDraw的话，必须加上作用域Brass::WtthDraw,负责会出现死循环
    std::cout << "BlassPlus::Withdraw()" << std::endl;
}

