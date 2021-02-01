# c++引用基本概念

## 1.引用的基本概念

变量名，本身是一段内存的引用，即别名\(alias\). 引用可以看作一个已定 义变量的别名。

引用的语法: Type& name = var;

```
#include <iostream>
using namespace std;
int main(void)
{
  int a = 10;//c编译器分配4个字节内存, a内存空间的别名
  int &b = a; //b就是a的别名

  a = 11; //直接赋值
  {
    int *p = &a;
    *p = 12;
    cout << a << endl;
  }
    b = 14;

}
```

## 2.引用的规则

* 1 .引用没有定义,是一种关系型声明。声明它和原有某一变量\(实体\)的关 系。故而类型与原类型保持一致,且不分配内存。与被引用的变量有相同的地址。
* 2 .声明的时候必须初始化,一经声明,不可变更。
* 3 .可对引用,再次引用。多次引用的结果,是某一变量具有多个别名。
* 4 .&符号前有数据类型时,是引用。其它皆为取地址。

```
int main(void)
{
  int a,b;
  int &r = a;
  int &r = b; //错误,不可更改原有的引⽤用关系
  float &rr = b; //错误,引⽤用类型不匹配 cout<<&a<<&r<<endl; //变量与引⽤用具有相>同
  的地址。
  int &ra = r; //可对引⽤用更次引⽤用,表⽰示 a 变量有两个别名,分别是 r 和 ra
  return 0;
}
```

## 3.引用作为函数参数

普通引用在声明时必须用其它的变量进行初始化，引用作为函数参数声明时不进行初始化.

```
#include <iostream>
using namespace std;
struct Teacher
{
    char name[64];
    int age ;
};

void printfT(Teacher *pT)
{
    cout<< pT->age <<endl;
}
//pT是t1的别名 ,相当于修改了t1
void printfT2(Teacher &pT)
{
    pT.age = 33;
    cout<<pT.age<<endl;
}
//pT和t1的是两个不同的变量
void printfT3(Teacher pT)
{
    cout<<pT.age<<endl;
    pT.age = 45; //只会修改pT变量 ,不会修改t1变量
}
int main(void)
{
    Teacher t1;
    t1.age = 35;
    printfT(&t1);
    printfT2(t1); //pT是t1的别名
    printf("t1.age:%d \n", t1.age); //33 printfT3(t1) ;// pT是形参 ,t1 copy⼀一份数据 给pT
    printf("t1.age:%d \n", t1.age); //33
    return 0;
}
```

## 4.引用存在的意义

1\)引用作为其它变量的别名而存在，因此在一些场合可以代替指针

2\)引用相对于指针来说具有更好的可读性和实用性

```
void swap(int a, int b); //⽆法实现两数据的交换
void swap(int *p, int *q); //开辟了两个指针空间实现交换
```

```
void swap(int &a, int &b){
    int tmp;
    tmp = a; a = b;
    b = tmp;
}
```
