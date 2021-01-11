# c++引用做函数的返回值

## 1.引用当函数的返回值

当函数返回值为引用时, 若返回栈变量: 不能成为其它引用的初始值\(不能作为左值使用\)

```
#include <iostream>
using namespace std;
int getA1() {
    int a;
    a = 10;
    return a;
}
int& getA2()
{
    int a;
    a = 10;
    return a;
}
int main(void)
{
    int a1 = 0;
    int a2 = 0;
    //值拷贝
    a1 = getA1();//ok
    //将⼀个引⽤用赋给⼀个变量，会有拷⻉贝动作
    //理解: 编译器类似做了如下隐藏操作，a2 = *(getA2())
    a2 = getA2();//ok
    //将一个引⽤用赋给另⼀个引⽤用作为初始值，由于是栈的引用，内存非法
    //因为引用的本质是一个常指针，当你返回的是栈空间的时候，执行完下面这句话，栈变量已经释放了，这个引用就指向了一个野地方。所以不能返回一个栈空间。
    int &a3 = getA2();//error
    cout <<"a1 = " <<a1<<endl;
    cout <<"a2 = " <<a2<<endl;
    cout <<"a3 = " <<a3<<endl; //非法值
    return 0;
}
```

## 2.函数返回值为引用，这个引用是静态变量或者全局变量

可以成为其他引用的初始值\(可作为右值使用，也可作为左值使用\)

```
#include <iostream>
using namespace std;
int getA1() {
    static int a;
    a = 10;
    return a;
}
int& getA2()
{
    static int a;
    a = 10;
    return a;
}
int main(void)
{
    int a1 = 0;
    int a2 = 0;
    //值拷⻉贝
    a1 = getA1();
    //将一个引⽤用赋给⼀一个变量，会有拷⻉贝动作
    //理解: 编译器类似做了如下隐藏操作，a2 = *(getA2())
    a2 = getA2();
    //将⼀个引⽤用赋给另⼀一个引⽤用作为初始值，由于是静态区域，内存合法,因为static是在全局区
    int &a3 = getA2();
    cout <<"a1 = " <<a1<<endl;//10
    cout <<"a2 = " <<a2<<endl;//10
    cout <<"a3 = " <<a3<<endl;//10
    return 0;
}
```

## 3.当一个函数返回引用时，这个函数可以当左值
```
#include <iostream>
using namespace std;
//函数当左值 //返回变量的值
int func1() {
    static int a1 = 10;
    return a1;
}
//返回变量本⾝
int& func2()
{
    static int a2 = 10;
    return a2;
}

int *j2()
{
    static int a = 10;
    a++;
    printf("a:%d \n", a);
    return &a;
}

int main(void)
{
  //函数当右值
  int c1 = func1();
  cout << "c1 = " << c1 <<endl;//10
  int c2 = func2(); //函数返回值是一个引⽤,并且当右值
  cout << "c2 = " << c2 <<endl;//10
  //函数当左值
  //func1() = 100; //error，因为是10 = 100肯定是错误的
  func2() = 100; //函数返回值是⼀个引⽤用,并且当左值。编译器帮我们打造了环境
  c2 = func2();
  cout << "c2 = " << c2 <<endl;//100

  *(j2()) = 200; //相当于我们程序员手工的打造 做左值的条件

  return 0;
}
```
