# c++函数模板
### 1.函数模板的好处
写一个交换函数
```
void myswap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void myswap(char &a, char &b)
{
    char t = a;
    a = b;
    b = t;
}
```
**使用函数模板**
语法格式：
```
template<typename T>
template<class T>

```
template 是语义是模板的意思,尖括号中先写关键字 typename 或是 class ,后 面跟一个类型 T,此类即是虚拟的类型。至于为什么用 T,用的人多了,也 就是 T 了。

```
template<typename T>
void myswap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}
int main(void)
{
int x=1; int y=2;
    myswap(x, y);
    cout <<"x: " << x <<", y:" << y <<endl;
    myswap<int>(x, y);
    cout <<"x: " << x <<", y:" << y <<endl;
    char a = 'a';
    char b = 'b';
    myswap(a, b);
    cout <<"a: " << a <<", b:" << b <<endl;
    myswap<char>(a, b);
    cout <<"a: " << a <<", b:" << b <<endl;
 }
```
**函数模板,只适用于函数的参数个数相同而类型不同,且函数体相同的情况。 如 果个数不同,则不能用函数模板。**

### 2.函数模板和普通函数的区别
```
#include <iostream>
using namespace std;
template <typename T>
void myswap(T &a, T &b)
{
  T t;
  t = a;
  a = b;
  b = t;
  cout<<"myswap 模板函数do"<<endl;
}
void myswap(char &a, int &b)
{
  int t;
  t = a;
  a = b;
  b = t;
  cout<<"myswap 普通函数do"<<endl;
}
int main() {
  char cData = 'a'; intiData= 2;
  myswap(cData, iData);
  myswap(iData, cData);
  // 普通函数会进⾏行隐⼠士的数据类型转换
   myswap<int>(cData, iData);
  158
  // 函数模板不提供隐式的数据类型转换 必须是严格的匹配 return 0;
}
```
**普通函数会进行隐士的数据类型转换, 函数模板不提供隐式的数据类型转 换 必须是严格的匹配。**

* 1. 当函数模板和普通函数都符合调用时,优先选择普通函数
* 2. 若显示使用函数模板,则使用<> 类型列表
* 3. 如果 函数模板产生更好的匹配 使用函数模板

```
#include <iostream>
using namespace std;
int Max(int a, int b)
{
    cout<<"int Max(int a, int b)"<<endl;
    return a > b ? a : b;
}
template<typename T>
T Max(T a, T b)
{
    cout<<"T Max(T a, T b)"<<endl;
    return a > b ? a : b;
}
template<typename T>
T Max(T a, T b, T c)
{
    cout<<"T Max(T a, T b, T c)"<<endl;
    return Max(Max(a, b), c);
}
int main() {
    int a = 1;
    int b = 2;
    cout<<Max(a, b)<<endl; //当函数模板和普通函数都符合调⽤用时,优先选择普通函数 cout<<Max<>(a, b)<<endl; //若显⽰示使⽤用函数模板,则使⽤用<> 类型列表
    cout<<Max(3.0, 4.0)<<endl; //如果 函数模板产⽣生更好的匹配 使⽤用函数模板 cout<<Max(5.0, 6.0, 7.0)<<endl; //重载
    cout<<Max('a', 100)<<endl; //调⽤用普通函数 可以隐式类型转换
    return 0;
}
```
