# c++中的抽象类在多继承中的应用
绝大多数面向对象语言都不支持多继承,绝大多数面向对象语言都支持接口的概念。

C++中没有接口的概念,C++中可以使用纯虚函数实现接口 接口类中只有函数原型定义，没有任何数据的定义.

```
#include <iostream>
using namespace std;
/*
C++中没有接⼝口的概念 C++中可以使⽤用纯虚函数实现接⼝口 接⼝口类中只有函数原型定义，没有任何数据的定义。
*/
class Interface1
{
public:
    virtual void print() = 0;
    virtual int add(int a, int b) = 0;
};

class Interface2
{
public:
    virtual void print() = 0;
    virtual int add(int a, int b) = 0;
    virtual int sub(int a, int b) = 0;
};

class parent
{
public:
    int a;
};

class Child : public parent, public Interface1, public Interface2
{
public:
    void print()
    {
        cout<<"Child::print"<<endl;
    }
    int add(int a, int b)
    {
        return a + b;
    }
    int sub(int a, int b)
    {
        return a - b;
    }
};

int main() {
    Child c;
    c.print();
    cout<<c.add(3, 5)<<endl;
    cout<<c.sub(4, 6)<<endl;
    Interface1* i1 = &c;
    Interface2* i2 = &c;
    cout<<i1->add(7, 8)<<endl;
    cout<<i2->add(7, 8)<<endl;
    return 0;
}
```
