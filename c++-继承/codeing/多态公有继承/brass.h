#ifndef __duotai_BRASS_H__
#define __duotai_BRASS_H__

class Brass
{
    private:
        std::string fullName;
        long acctNum;
        double balance;
    public:
        Brass(const std::string &s, long an, double bal);
        void Deposit(double amt);
        double Balance() const;
        virtual void Withdraw(double amt) const;
        virtual void ViewAcct() const;
        virtual ~Brass();
};

/*
使用virtual的好处：
    如果没有使用virtual的话，程序将根据引用类型或者指针类型选择方法。
    Brass dom("dom", 11223, 34.4)
    BrassPlus bp("bp", 12118, 34.6);
    Brass &b1 = dom;
    Brass &b2 = bp;（指针也是一样）
    b1.ViewAcct(); //会调用父类方法（指针也是一样）
    b2.ViewAcct();//会调用父类方法（指针也是一样）
    但是使用了virtual之后，就会根据指向的对象不同，而调用不同的类的方法。

    总结：所以如果要在子类中重新定义父类的方法，通常应该将父类声明为virtual，这样，程序将根据不同指向的不同的对象，调用不同的方法。
*/
class BlassPlus : public Brass
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BlassPlus(const std::string &s, long an, double bal, double ml, double r);
        BlassPlus(const Brass &ba, double ml, double r);
        virtual void Withdraw(double amt) const;
        virtual void ViewAcct() const;
        void ResetMax(double m);
        void ResetRate(double r);
        void ResetOwes();
};

#endif //!__多态公有继承_BRASS_H__