# const汇总

### 1.c语言中的const
```
void main()
{
    const int a = 0;//这两种写法是一样的，代表一个常整形数
    int const b = 1;//加了const就不能随便的改变它的值
    const int *c;//如果const放在*的左边。修饰的c所指向的内存空间不能被修改
    int * const d ;//如果const放在*的右边，表示const修饰d,d是指针变量，不能改变它的指向，与它所指向的内存空间没有任何关系
    d = 0xaa11;//不能改变
    const char * const e;//指针变量和所指向的内存空间都不能被修改
    system("pause");
}  
```

### 2.const修饰基本数据类型
```
 const int a=10;  等价的书写方式： int const a=10;
 const int arr[3]={1,2,3};   等价的书写方式： int const arr[3]={1,2,3};
```
表示常量，在使用这些常量的时候，只要不改变这些常量的值就好。

### 3.const修饰指针
```
const int * a = &b;
int const * a = &b;
```
这两种等价，都表示指针所指向的内容为常量。指针所指向的内容不可改变。
```
int * const a = &b; 表示指针变量是一个常量，即不能改变指针的指向。
```
```
const int* const a = &b; 指针变量和指针所指向的内存空间都是不可改变的。
```
### 4.const修饰引用
```
int const &a=x;
const int &a=x;
```
写法是等价的。

* 1.const 对象的引用必须是 const 的,将普通引用绑定到 const 对象是不 合法的。这个原因比较简单。既然对象是 const 的,表示不能被修改,引用当然 也不 能修改,必须使用 const 引用。实际上,
```
const int a=1;
int &b=a; 这种写法是不合法 的,编译不过。
```
* 2.const 引用可使用相关类型的对象\(常量,非同类型的变量或表达式\)初 始化。这个是 const 引用与普通引用最大的区别。
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
//普通引⽤用
int a = 10;
int &b = a;
cout << "b = " << b << endl;
//常引⽤用
int x = 20;
const int &y = x;
y = 21;//常引⽤用是限制变量为只读 不能通过y去修改x了 /error
return 0;
```

* 3.const引用的初始化
```
#include <iostream>
using namespace std;
int main(void)
{
  //1> 引用变量 初始化 常引⽤用
  int x1 = 30;
  const int &y1 = x1; //用x1变量去初始化 常引⽤
  //2> 引用字面量 初始化常量引⽤用
  const int a = 40; //c++编译器把a放在符号表中
  //int &m = 41; //error , 普通引⽤用 引⽤用一个字⾯面量 请问字⾯面量有没有内存地址
  const int &m = 43; //c++编译器 会分配内存空间 // int temp = 43
  return 0;
}
```
那么,为什么非 const 的引用不能使用相关类型初始化呢?实际上,const引用使用相关类型对象初始化时发生了如下过程:

  ```
  int temp = val;
  const int &ref = temp;
  ```

* 4.const引用做函数参数

  ```
  struct Teacher
  {
      char name[64];
      int age ;
  };
  void printTeacher(const Teacher &myt)
  {
    //常引⽤用 让 实参变量 拥有只读属性
    //myt.age = 33; printf("myt.age:%d \n", myt.age);
  }
  int main(void)
  {
      Teacher  t1;
      t1.age = 36;
      printTeacher(t1);
      return 0;
  }

  ```
* 5.const引用结论
```  
结论:
1)const int & e 相当于 const int * const e
2)普通引用 相当于 int *const e
3)当使用常量(字面量)对const引用进行初始化时，C++编译器会为常量值 分配空间，并将引用名作为这段空间的别名
4)使用字面量对const引用初始化后，将生成一个只读变量
```

### 5.const修饰函数
* 1.const修饰成员函数

  **1.任何不会修改数据成员的函数都应该声明为const 类型。如果在编写const 成员函数时，不慎修改了数据成员，或者调用了其它非const 成员函数，编译器将指出错误**

  **2.const成员函数不能修改对象的数据成员而且不能调用非const函数，为什么不能调用非const函数？因为非const函数可能修改数据成员，const成员函数是不能修改数据成员的，所以在const成员函数内只能调用const函数。**
  ```
  class Stack  
  {  
  public:  
   void Push(int elem);  
   int Pop(void);  
   int GetCount(void) const; // const 成员函数  
  private:  
   int m_num;  
   int m_data[100];  
  };
  ```
  **const 成员函数的声明看起来怪怪的：const 关键字只能放在函数声明的尾部，大概是因为其它地方都已经被占用了**

* 2.const修饰函数返回值

  **如果给以“指针传递”方式的函数返回值加const 修饰，那么函数返回值（即指针）的内容不能被修改，该返回值只能被赋给加const 修饰的同类型指针**
  ```
  const char * GetString(void);
  如下语句将出现编译错误：
  char *str = GetString();//error
  正确的用法是:
  const char *str = GetString();
  ```
  **如果函数返回值是“值传递”，那么返回值加const没有任何意义，因为函数返回值会被复制到一个临时的存储单元中，所以加const没有意义**
  ```
  const int GetInt(void);没有意义
  ```
