# c++函数重载

### 1.重载规则
* 1.函数名相同
* 2.参数个数不同,参数的类型不同,参数顺序不同,均可构成重载
* 3.返回值类型不同则不可以构成重载。
```
void func(int a); //ok
void func(char a); //ok
void func(char a,int b); //ok
void func(int a, char b); //ok
char func(int a); //与第⼀一个函数有冲突
```

### 2.函数重载的调用规则
1.将所有同名函数作为候选者

2.尝试寻找可行的候选函数

3.精确匹配实参

4.通过默认参数能够匹配实参

5.通过默认类型转换匹配实参

6.匹配失败

7.最终寻找到的可行候选函数不唯一，则出现二义性，编译失败。

8.无法匹配所有候选者，函数未定义，编译失败。
```
void print(double a){
    cout<<a<<endl;
}
void print(int a){
    cout<<a<<endl;
}
int main() {
    print(1); // print(int)
    print(1.1); // print(double)
    print('a'); // print(int)
    print(1.11f); // print(double)
return 0; }
```

### 2.函数重载，不要使用默认参数，会出现二义性
```
int func(int a, int b, int c = 0)
{
    return a * b * c;
}
int func(int a, int b)
{
  return a + b;
}
int func(int a)
{
  return a;
}
int main()
{
      int c = 0;
      c = func(1,2); //error. 存在⼆二义性，调⽤用失败，编译不能通过
      printf("c = %d\n", c);
      return 0;
  }
```

### 3.函数重载的底层实现
C++利用 name mangling(倾轧)技术,来改名函数名,区分参数不同的同名函数。

实现原理:用 v c i f l d 表示 void char int float long double 及其引 用。
```
void func(char a);                  // func_c(char a)
void func(char a, int b, double c); //func_cid(char a, int b, double c)
```
