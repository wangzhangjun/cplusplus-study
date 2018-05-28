# c++虚析构函数

* 构造函数不能是虚函数。建立一个派生类对象时，必须从类层次的根开 始，沿着继承路径逐个调用基类的构造函数。
* 析构函数可以是虚的。虚析构函数用于指引delete运算符正确析构动态对象。通过父类指针调用所有的子类析构函数

```
#include <iostream>
using namespace std;
class A
{
public:
      A()
     {
     }
    virtual ~A()
    {
        delete [] p;
        printf("~A()\n");
    }
 private:
    char *p;
};

class B : public A
{
public:
  B() {
  }
 ~B() {
    delete [] p;
    printf("~B()\n");
  }
private:
    char *p;
};

class C : public B
{
public:
  C() {
  }
  ~C() {
    delete [] p;
    printf("~C()\n");
  }
private:
    char *p;
};

//通过⽗父类指针 把所有的⼦子类对象的析构函数 都执⾏行⼀一遍
//通过⽗父类指针 释放所有的⼦子类资源
void howtodelete(A *base)
{
    delete base;
}

int main() {
  C *myC = new C;
  //delete myC; //直接通过⼦子类对象释放资源 不需要写virtual
  howtodelete(myC);//通过⽗父类的指针调⽤用释放⼦子类的资源
  return 0;
}
```
