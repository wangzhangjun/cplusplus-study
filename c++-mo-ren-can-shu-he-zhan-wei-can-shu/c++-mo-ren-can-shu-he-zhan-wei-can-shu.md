# c++默认参数和占位参数

## 1.默认参数

通常情况下,函数在调用时,形参从实参那里取得值。对于多次调用用一函 数同一 实参时,C++给出了更简单的处理办法。给形参以默认值,这样就不用从 实参那里取值了.

```text
//2 在默认参数规则 ，如果默认参数出现，那么右边的都必须有默认参数
float volume(float length, float weight = 4,float high = 5)
{
    return length*weight*high;
}
int main() {
    float v = volume(10);
    float v1 = volume(10,20);
    float v2 = volume(10,20,30);
    cout<<v<<endl;
    cout<<v1<<endl;
    cout<<v2<<endl;
    return 0;
}
```

## 2.默认参数规则

只有参数列表后面部分的参数才可以提供默认参数值,一旦在一个函数调用中开始使用默认参数值，那么这个参数后的所有参数都必须使用默认参数值.

## 3.占位参数

```text
#include <iostream>
/*
  函数占位参数
  占位参数只有参数类型声明，⽽而没有参数名声明
  ⼀一般情况下，在函数体内部⽆无法使⽤用占位参数
*/
int func(int a, int b, int)
{
  return a + b;
}
int main()
{
    func(1, 2); //error, 必须把最后⼀一个占位参数补上。 //好悲剧的语法 -_-!
    printf("func(1, 2, 3) = %d\n", func(1, 2, 3));
    return 0;
}
```

**占位参数在c++中没有什么实际的作用，一般和默认参数结合起来使用**

```text
#include <iostream>
/*
可以将占位参数与默认参数结合起来使⽤用 意义
为以后程序的扩展留下线索 兼容C语⾔言程序中可能出现的不规范写法
*/ //C++可以声明占位符参数，占位符参数⼀一般⽤用于程序扩展和对C代码的兼容
int func2(int a, int b, int = 0)
{
  return a + b;
}
int main()
{
  //如果默认参数和占位参数在⼀一起，都能调⽤用起来 func2(1, 2);
  func2(1, 2, 3);
  return 0;
}
```

