# c++类模板的派生
```
#include <iostream>
using namespace std;
template<class T>
class A
{
public:
    A(T a) {
        this->a = a;
}
protected:
  T a;
};

//模板类派⽣生普通类
//结论: ⼦子类从模板类继承的时候,需要让编译器知道 ⽗父类的数据类型具体是什么(数据类型的本 质:固定⼤大⼩小内存块的别名)A<int>
class B : public A<int>
{
public:
    B(int a, int b) : A<int>(a)
    {
      this->b = b;
    }
    void printB()
    {
      cout<<"b:  "<<b <<endl;
    }
private:
  int b;
};

//模板类派⽣生模板类
template <class T> class C :public A<T> {
public:
    C(T a, T c): A<T>(a)
    {
this->c = c; }
    void printC()
    {
        cout <<"C : " << c <<endl;
    }
    private: T c;
};
```
