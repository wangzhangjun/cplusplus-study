# c++中的重载，重写，重定义
### 1.重载
> 1.相同的范围

>  2.函数名字相同

>  3.参数不同

>  4.virtual关键字可有可无

### 2.重写（覆盖）:是指派生类函数覆盖基类函数
> 1.不同的范围，分别位于基类和派生类中。

> 2.函数的名字相同

> 3.参数相同

> 4.基类函数必须有virtual关键字

### 3.重定义(隐藏): 是指派生类的函数屏蔽了与其同名的基类函数
> 1.如果派生类的函数和基类的函数同名，但是参数不同，此时，不管有无 virtual，基类的函数被隐藏。

> 2.如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没 有vitual关键字，此时，基类的函数被隐藏。

### 4.demo
```
#include <cstdlib>
#include <iostream>

using namespace std;

class Parent01
{
public:
    Parent01()
    {
        cout<<"Parent01:printf()..do"<<endl;
    }
public:
    void func()
    {
        cout<<"Parent01:void func()"<<endl;
    }

    void abcd()
    {
        cout<<"Parent01:void func()"<<endl;
    }

    virtual void func(int i)
    {
        cout<<"Parent:void func(int i)"<<endl;
    }

    virtual void func(int i, int j)
    {
        cout<<"Parent:void func(int i, int j)"<<endl;
    }
};


//重写的两种情况
//如果函数重写，在父类中增加了virtual关键字, 将能产生多态。。。。
//如果函数重写，没有加virtual关键字，，相当于在子类中重定义。。。。。，不会发生多态。。。
class Child01 : public Parent01
{

public:

    //原因是发生了 名称覆盖，把子类中的没有函数参数的，这个函数abcd名称覆盖了。。。，一般情况下编译不通过
    //在子类中，是不能重载父类的函数的。编译器就是这么做的，顺从。。。。
    void abcd(int a, int b)
    {
        cout<<"Child01:void func()"<<endl;
    }

    //此处2个参数，和子类func函数是什么关系(重写)
     void func(int i, int j)
    {
        cout<<"Child:void func(int i, int j)"<<" "<<i + j<<endl;
    }

    //此处3个参数的，和子类func函数是什么关系
    void func(int i, int j, int k)
    {
        cout<<"Child:void func(int i, int j, int k)"<<" "<<i + j + k<<endl;
    }
};

void run01(Parent01* p)
{
    p->func(1, 2);
}

int main()
{
    Parent01 p;

    //这三个都是调用父类的函数
    p.func();
    p.func(1);
    p.func(1, 2);


    Child01 c;
    //c.func(); //编译不通过，因为发生了重定义。
    c.func(1,2); //调用子类的，发生了函数重写

    run01(&p);
    run01(&c);//多态
    return 0;
}
```
