# c++类模板中的static变量
```
#include <iostream>
using namespace std;
template <class T>
class A{
    public:
        static T s_value;
};

//静态变量需要在类的外部初始化
template <class T>
T A<T>::s_value = 0;

/*
  当编译器看⻅见 A<int> 被调⽤用， 将执⾏行⼆二次编译， ⽣生成如下的类A class A
  {
  public:
  static int s_value;
  };
  int A::s_value = 0;
*/

 /*
当编译器看⻅见 A<char> 被调⽤用， 将执⾏行⼆二次编译， ⽣生成如下的类A class A
{
public:
   static char s_value;
 };
    char A::s_value = 0;
*/

int main(void)
{
    A<int> a1, a2, a3; //class A <int>家族的 对象 A<char> b1, b2, b3; // class A <char>家族的 对象
    a1.s_value = 10;
    b1.s_value = 'a';
    cout << a1.s_value << endl;
    cout << b1.s_value << endl;
}
```
