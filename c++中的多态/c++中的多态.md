# c++中的多态

### 1.多态实现的前提
赋值兼容是一种默认行为,不需要任何的显示的转化步骤。 赋值兼容规则中所指的替代包括以下的情况:
* 1.派生类的对象可以赋值给基类对象。 ︎
* 2.派生类的对象可以初始化基类的引用。
* 3.︎派生类对象的地址可以赋给指向基类的指针。

在替代之后,派生类对象就可以作为基类的对象使用,**但只能使用从基类继承的成员。**

### 2.没有多态会怎样
```
#include <iostream>

using namespace std;

//定义一个子类和一个父类
class Parent
{
public:
    Parent(int a = 0)
    {
        this->a = a;
    }
    void print()
    {
        cout<<"父类a:"<<a<<endl;
    }
protected:
private:
    int a;
};

class Child : public Parent
{
public:
    Child(int b = 0)
    {
        this->b = b;
    }
    void print()   //重定义，父类的print被隐藏
    {
        cout<<"子类b:"<<b<<endl;
    }
protected:
private:
    int  b;
};

/*
编译器认为最安全的做法是编译到父类的print函数， 因为父类和⼦类肯定都有相同的print函数。
*/

void HowToPrint1(Parent *p)
{
    p->print(); //一句话，有多种效果，有多种表现形态把。。。//这个功能的就是多态
}
void HowToPrint2(Parent &myp)
{
    myp.print();
}
int main()
{
    Parent p1;
    Child c1;

    p1.print();//父类的
    c1.print();//子类的。

    HowToPrint1(&p1);//父类的
    HowToPrint1(&c1);//父类的

    HowToPrint2(p1);//还是打印父类的
    HowToPrint2(c1);//还是打印父类的

    return 0;
}
```

### 3.面向对象新需求
编译器的做法不是我们期望的：
  * 根据实际的对象类型来判断重写函数的调用;
  * 如果父类指针指向的是父类对象则调用父类中定义的函数;

如果父类指针指向的是子类对象则调用子类中定义的重写函数;

### 4.解决方案
* C++中通过virtual关键字对多态进行支持.
* 使用virtual声明的函数被重写后即可展现多态特性

```
#include <iostream>

using namespace std;

//定义一个子类和一个父类
class Parent
{
public:
    Parent(int a = 0)
    {
        this->a = a;
    }
    virtual void print()
    {
        cout<<"父类a:"<<a<<endl;
    }
protected:
private:
    int a;
};

class Child : public Parent
{
public:
    Child(int b = 0)
    {
        this->b = b;
    }
    void print()  //重写
    {
        cout<<"子类b:"<<b<<endl;
    }
protected:
private:
    int  b;
};

void HowToPrint1(Parent *p)
{
    p->print(); //一句话，有多种效果，有多种表现形态把。。。//这个功能的就是多态
}
void HowToPrint2(Parent &myp)
{
    myp.print();
}
int main()
{
    Parent p1;
    Child c1;

    HowToPrint1(&p1);
    HowToPrint1(&c1);

    HowToPrint2(p1);//还是打印父类的
    HowToPrint2(c1);//还是打印父类的

    return 0;
}
```
### 5.多态成立的条件
* 1.要有继承
* 2.要有虚函数重写
* 3.要有父类指针(父类引用)指向子类对象
