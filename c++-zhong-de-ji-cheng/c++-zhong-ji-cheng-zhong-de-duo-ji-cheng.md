# c++中继承中的多继承

## 1.多继承的语法规则

```text
#include <iostream>
using namespace std;
class Base1
{
public:
    int b1;
    Base1()
    {
        b1 =  1;
    }
};
class Base2
{
public:
    int b2;
    Base2()
    {
        b2 = 2;
    }
};
class Child : public Base1, public Base2
{
public:
    Child()
    {
        cout<<"子类"<<endl;
    }
    void printB()
    {
        cout<<"b1:"<<b1<<"b2:"<<b2<<endl;
    }
};
void main()
{
    Child c1;
    c1.printB();
    system("pause");
}
```

![](../.gitbook/assets/markdown-img-paste-2018052516321611.png)

## 2.多继承中的二义性

多继承的二义性通过virtual关键字来解决

```text
#include "iostream"
using namespace std;

class B
{
public:
    int i;
protected:
private:
};

class B1 : virtual public B
{
public:
    int b1;
protected:
private:
};

class B2 :virtual  public B
{
public:
    int b2;
protected:
private:
};

class C :public B1, public B2
{
public:
protected:
private:
};
void main()
{
    C c1;
    c1.b1 = 10;
    c1.b2 = 20;
    c1.i = 100; //这里不知道是谁的i，所以通过virtual关键字来解决,这里的i是直接从爷爷继承过来的。和B1,B2没有关系。virutal只是对从爷爷继承过来的公共的变量起作用，对于B1和B2特有的没有这个效果。
}
```

