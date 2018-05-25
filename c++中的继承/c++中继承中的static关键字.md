# c++中继承中的static关键字
1.基类定义的静态成员，将被所有派生类共享

2.根据静态成员自身的访问特性和派生类的继承方式，在类层次体系中具 有不同的访问性质 (遵守派生类的访问控制)

3.派生类中访问静态成员，用以下形式显式说明:
```
类名::成员
```
或通过对象访问
```
对象名 . 成员
```

### 1.demo，public继承
```
#include <iostream>

using namespace std;

class B{
public:
    static void add(){
        i++;
    }

    static int i; //如果是Private的，在子类中不会被访问
    void out(){
        cout << "static i=" << i << endl;
    }
private:
};

int B::i = 0;

class D: public B
{
public:
    void f()
    {
        i = 5;
        add();
        B::i++;
        B::add();

    }
};

int main(int argc, char *argv[])
{
    B x; D y;
    x.add();
    x.out();
    y.f();

    cout << "static i " << B::i<<endl;
    cout << "static i " << x.i<<endl;
    cout << "static i " << y.i<<endl;
    return 0;
}

```
### 2.demo，private继承
```
#include <iostream>

using namespace std;

class B{
public:
    static void add(){
        i++;
    }

    static int i;
    void out(){
        cout << "static i=" << i << endl;
    }
private:
};

int B::i = 0;

class D: private B
{
public:
    void f()
    {
        i = 5;
        add();
        B::i++;
        B::add();
        cout << "in class D::static i:" << i << endl;
    }
};

int main(int argc, char *argv[])
{
    B x; D y;
    x.add();
    x.out();
    y.f();

    cout << "static i " << B::i<<endl;
    cout << "static i " << x.i<<endl;
//    cout << "static i " << y.i<<endl;无法访问
    return 0;
}

```
