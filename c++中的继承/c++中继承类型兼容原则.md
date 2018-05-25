# c++中继承类型兼容原则
类型兼容规则是指在需要基类对象的任何地方，都可以使用公有派生类
的对象来替代。通过公有继承，派生类得到了基类中除构造函数、析构函数之
外的所有成员。这样，公有派生类实际就具备了基类的所有功能，凡是基类能
解决的问题，公有派生类都可以解决。
```
1.子类对象可以当作父类对象使用
2.子类对象可以直接赋值给父类对象
3.子类对象可以直接初始化父类对象
4.父类指针可以直接指向子类对象
5.父类引用可以直接引用子类对象
```
**一般情况下，子类的内存空间都是大于父类的内存空间，所以不能用父类来初始化子类**

在替代之后，派生类对象就可以作为基类的对象使用，但是只能使用从基类继承的成员。
```
子类就是特殊的父类 (base *p = &child;)
```

### demo
```
#include <iostream>
using namespace std;
class Parent
{
public:
    void printP()
    {
        cout << "parent...." << endl;
    }
};
class Child : public Parent
{
    public:
        void printC()
        {
            cout << "child..." << endl;
} };
void print01(Parent  *p)
{
    p->printP();
}
void print02(Parent  &p)
{
    p.printP();
}
int main() {
    Child c1;
    c1.printC();
    Parent *p = NULL; //可以⽤用⽗父类指针 指向 ⼦子类对象 p = &c1;
    p->printP(); //执⾏行⽗父类的函数
    Child   c2;
    Parent  p2;
    print01(&p2);
    print01(&c2); //⽗父类指针指向⼦子类对象
    print02(p2);
    print02(c2); //⽗父类引⽤用指向⼦子类对象
    //第⼆二层含义 ⽤用⼦子类初始化⽗父类对象 Child c3;
    Parent p3 = c3;
    return 0;
}

```
