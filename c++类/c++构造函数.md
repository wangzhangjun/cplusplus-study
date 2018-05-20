# c++构造函数和析构函数

### 1.构造函数定义
C++中的类可以定义与类名相同的特殊成员函数，这种与类名相同的成员 函数叫做构造函数。
```
class 类名 {
  类名(形式参数) {
    构造体
  }
}
```
```
class A {
  A(形参) {
  }
}
```
规则：
* 1.在对象创建时自动调用,完成初始化相关工作。
* 2.无返回值,与类名同,默认无参,可以重载,可默认参数。
* 3.一经实现,默认不复存在。

### 2.析构函数的定义
```
class 类名 {
  ~类名() {
    析构体
  }
}
```
规则：
* 1.对象销毁时,自动调用。完成销毁的善后工作。 
* 2.无返值 ,与类名同。无参。不可以重载与默认参数。

### 3.构造函数的分类以及调用
```
class Test {
  public:
  //⽆无参数构造函数
  Test() {
    ;
  }
  //带参数的构造函数
  Test(int a, int b) {
    ;
  }
  //赋值构造函数
  Test(const Test &obj) {
    ;
  }
  private:
    int a;
    int b;
 };
```
### 3.1. 无参函数的调用
```
#include <iostream>
using namespace std;
class Test {
public:
//⽆无参数构造函数
Test() {
  a = 0;
  b = 0;
  cout <<"Test() ⽆无参构造函数执⾏行" <<endl;
}
private:
    int a;
    int b;
};
int main(void)
{
 Test t; //调⽤用⽆无参构造函数
 return 0;
}
```

### 3.2. 有参函数的调用
```
#include "iostream"
using namespace std;
class Test
{
public:
    Test(int mya)
    {
      a= mya;  
    }

    Test(int a, int b)
    {
      cout <<"a = " << a << ", b = " << b <<endl;
    }
protected:
private:
    int a;
};
void main()
{
    //有参构造函数的三种构造函数的调用方法
    Test t1(10);//第一种：c++默认调用有参构造函数 自动调用
    Test t3 = Test(12);//第二种：c++默认调用有参构造函数 程序员手工调用构造函数
}  
```
