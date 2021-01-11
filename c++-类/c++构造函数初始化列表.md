# c++构造函数初始化列表

初始化列表出现的原因：当以类中含有另一个类时，无法初始化。

```text
#include "iostream"
using namespace std;

class A
{
public:
    A(int _a1)
    {
        a1 = _a1;
    }
protected:
private:
    int a1;
};

//构造函数的初始化列表产生原因
//语法现象
class B
{
public:
    B():mya(12),mya2(100)
    {
        ;
    }
    //成员变量的初始化顺序与声明的顺序相关(谁先声明，谁就先初始化)，与在初始化列表中的顺序无关.
    //注意这里的mya和mya2是一个对象，所以会调用类的构造函数，如果仅仅是个变量（int 等）或者是个指针就是直接赋值
    B(int x, int y):mya(y),mya2(101)
    {
        b1 = x;
    }
protected:
private:
    int b1;
    A mya2;
    A mya;

};

void main()
{
    A a1(10);
    B b1(10, 20);
    system("pause");
}
```

## 2.当一个类中含有const，或者引用时，也要通过初始化列表进行初始化

```text
#include <iostream>
using namespace std;
class ABC
{
public:
   ABC(int a, int b, int c)
   {
       this->a = a;
       this->b = b;
       this->c = c;
       printf("a:%d,b:%d,c:%d \n", a, b, c);
       printf("ABC construct ..\n");
   }
~ABC() {
       printf("a:%d,b:%d,c:%d \n", a, b, c);
       printf("~ABC() ..\n");
   }
private:
   int a;
   int b;
   int c;
 };
class MyD
{
public:
   MyD():abc1(1,2,3),abc2(4,5,6),m(100)
    {
     cout<<"MyD()"<<endl;
    }
     ~MyD()
    {
        cout<<"~MyD()"<<endl;
    }
private:
    ABC abc1;
    ABC abc2;
    const int m;
};
int main() {
  MyD myD;
  return 0;
}
```

* 当类成员中含有一个const对象时，或者是一个引用时，他们也必须要通 过成员初始化列表进行初始化，因为这两种对象要在声明后马上初始化，而在构造函数中，做的是对他们的赋值，这样是不被允许的。
* 初始化列表中的初始化顺序,与声明顺序有关,与前后赋值顺序无关
