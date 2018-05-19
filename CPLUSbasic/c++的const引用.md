# c++的const引用

### 1.const引用
const 引用有较多使用。它可以防止对象的值被随意修改。因而具有一 些特性。
* 1.const 对象的引用必须是 const 的,将普通引用绑定到 const 对象是不 合法的。这个原因比较简单。既然对象是 const 的,表示不能被修改,引用当然 也不 能修改,必须使用 const 引用。实际上,
```
const int a=1;
int &b=a; 这种写法是不合法 的,编译不过。
```
* 2.const 引用可使用相关类型的对象(常量,非同类型的变量或表达式)初 始化。这个是 const 引用与普通引用最大的区别。
```
const int &a=2; //合法的
double x=3.14;
const int &b=a;
```

```
#include <iostream>
using namespace std;
int main(void)
{
//普通引⽤用 int a = 10; int &b = a;
   cout << "b = " << b << endl;
//常引⽤用
int x = 20; const int &y = x; //y = 21;
//常引⽤用是限制变量为只读 不能通过y去修改x了 /error
return 0;
```

### 2.const引用的原理
const 引用的目的是,禁止通过修改引用值来改变被引用的对象。const 引用的 初始化特性较为微妙,可通过如下代码说明:
```
double val = 3.14;
const int &ref = val;
double & ref2 = val;
cout<<ref<<" "<<ref2<<endl;//3 3.14
val = 4.14;
cout<<ref<<" "<<ref2<<endl;//3 4.14
```
why?因为 ref 是 const 的,在初始化的过 程中已经给定值,不允许修改。而被引用的对象是 val,是非 const 的,所以 val 的修改并未 影响 ref 的值,而 ref2 的值发生了相应的改变。

那么,为什么非 const 的引用不能使用相关类型初始化呢?实际上,const 引用 使用相关类型对象初始化时发生了如下过程:
```
int temp = val;
const int &ref = temp;
```

### 3.const 引用的初始化
```
#include <iostream>
using namespace std;
int main(void)
{
  //1> ⽤用变量 初始化 常引⽤用
  int x1 = 30;
  const int &y1 = x1; //⽤用x1变量去初始化 常引⽤用
  //2> ⽤用字⾯面量 初始化 常量引⽤用
  const int a = 40; //c++编译器把a放在符号表中
  //int &m = 41; //error , 普通引⽤用 引⽤用⼀一个字⾯面量 请问字⾯面量有没有内存地址
  const int &m = 43; //c++编译器 会 分配内存空间 // int temp = 43
  return 0;
}
```

### 4.const引用做函数参数
```
struct Teacher
{
    char name[64];
    int age ;
};
void printTeacher(const Teacher &myt)
{
  //常引⽤用 让 实参变量 拥有只读属性 //myt.age = 33; printf("myt.age:%d \n", myt.age);
}
int main(void)
{
    Teacher  t1;
    t1.age = 36;
    printTeacher(t1);
    return 0;
}
```
### 5.结论
```
结论:
1)const int & e 相当于 const int * const e
2)普通引用 相当于 int *const e
3)当使用常量(字面量)对const引用进行初始化时，C++编译器会为常量值 分配空间，并将引用名作为这段空间的别名
4)使用字面量对const引用初始化后，将生成一个只读变量
```
