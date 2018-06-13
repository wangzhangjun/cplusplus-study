# c++中的纯虚函数
纯虚函数是一个在基类中说明的虚函数，在基类中没有定义，要求任何
派生类都定义自己的版本
  纯虚函数为个派生类提供一个公共界面(接口的封装和设计、软件的模
块功能划分)

纯虚函数的语法：
```
 virtual 类型 函数名(参数表) = 0;
```

**一个具有纯虚函数的基类称为抽象类。**

* 1.含有纯虚函数的类,称为抽象基类,不可实列化。即不能创建对象,存在 的意义 就是被继承,提供族类的公共接口。

* 2.纯虚函数只有声明,没有实现,被“初始化”为 0。

* 3.如果一个类中声明了纯虚函数,而在派生类中没有对该函数定义,则该虚函数在 派生类中仍然为纯虚函数,派生类仍然为纯虚基类。

```
#include <iostream>

using namespace std;

class Figure  //抽象类
{
public:
    virtual void getArea() = 0; //纯虚函数
};

class Cirle: public Figure
{
public:
    Cirle(int a, int b){
        this->a = a;
        this->b = b;
    }

    virtual void getArea(){
        cout<<"圆形的⾯面积: "<<3.14*a*a<<endl;
    }
private:
    int a;
    int b;
};

class Tri : public Figure
{
public:
    Tri(int a, int b)
    {
        this->a = a;
        this->b = b; }
    virtual void getArea()
    {
        cout<<"三⾓角形的⾯面积: "<<a*b/2<<endl;; }
private:
    int a;
    int b;
};

class Square : public Figure
{
public:
    Square(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    virtual void getArea()
    {
        cout<<"四边形的⾯面积: "<<a*b<<endl;; }
private:
    int a;
    int b;
};

void area_func(Figure *base)
{
    base->getArea(); //会发⽣生多态
     }



int main() {
    std::cout << "Hello, World!" << std::endl;
    //Figure f; //抽象类不能被实例化
    Figure *base = NULL; //抽象类不能被实例化
    Cirle c1(10, 20);
    Tri t1(20, 30);
    Square s1(50, 60);
//⾯面向抽象类编程(⾯面向⼀一套预先定义好的接⼝口编程)
    area_func(&c1);
    area_func(&t1);
    area_func(&s1);
    return 0;
}
```
