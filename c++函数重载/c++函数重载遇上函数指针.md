# c++函数重载遇上函数指针

### 1.函数指针复习
```
//⽅方法⼀一:
//声明⼀一个函数类型
typedef void (myTypeFunc)(int a,int b);
//定义⼀一个函数指针
myTypeFunc *myfuncp = NULL; //定义⼀一个函数指针 这个指针指向函数的⼊入⼝口地址


//⽅方法⼆二:
//声明⼀一个函数指针类型
typedef void (*myPTypeFunc)(int a,int b) ; //声明了⼀一个指针的数据类型 //定义⼀一个函数指针
myPTypeFunc fp = NULL; //通过 函数指针类型 定义了 ⼀一个函数指针 ,


//⽅方法三:
//定义⼀一个函数指针 变量
void (*myVarPFunc)(int a, int b);
```

### 2.函数指针和函数重载的结合
```
/*
函数重载与函数指针
当使⽤用重载函数名对函数指针进⾏行赋值时
根据重载规则挑选与函数指针参数列表⼀一致的候选者
严格匹配候选者的函数类型与函数指针的函数类型
*/
#include <iostream>
using namespace std;
int func(int x) // int(int a)
{
  return x;
}
int func(int a, int b)
{
return a + b; }
int func(const char* s)
{
    return strlen(s);
}
typedef int(*PFUNC)(int a); // int(*)(int a)在这里就已经决定了重载规则
typedef int(*PFUNC2)(int a, int b); // int(*)(int a, int b)在这里就已经决定了重载规则
int main() {
    int c = 0;
    PFUNC p = func;
    c = p(1);
    printf("c = %d\n", c);
    PFUNC2 p2 = func;
    c = p2(1, 2);
    printf("c = %d\n", c);
    return 0;
}
```
