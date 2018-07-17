# c++类模板

### 1.类模板的定义
类模板与函数模板的定义和使用类似，我们已经进行了介绍。 有时，有 两个或多个类，其功能是相同的，仅仅是数据类型不同，所以将类中的类型进 行泛化。
```
template<typename T>
class A
{
}
```

### 2.简单的类模板
```
#include <iostream>
 using namespace std;
 template<typename T>
 template<class T>
 //定义类模板 要在类的头部之前加⼊入template<typename T> 或者 165
class A
{
  public:
    A(T t)
    {
      this->t = t;
    }
    T &getT() {
      return t;
    }
public:
  T t;
};
int main(void)
{
    //在定义⼀一个对象的时候，要明确此类所泛化的具体类型 A<int> a(100);
    cout << a.getT() << endl;
    return 0;
}


```
