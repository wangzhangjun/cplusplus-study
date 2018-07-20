# c++中的const_cast去掉const属性转换
```
 const_cast<目标类型> (标识符) //目标类类型只能是指针或引用。
```

```
#include <iostream>
#include <string>

using namespace std;

int main() {

//基础数据类型
    int a = 10;
    const int& b = a;
//    b = 20; 错误
    int &c = const_cast<int &>(b);
    c = 20;


    //指针
    const int *p = NULL;
    int *p2 = const_cast<int *>(p); //去除const属性给一个新的变量
    int *p3 = NULL;
    const int *p4 = const_cast<const int *>(p3);//增加const属性给一个新的变量

    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;

    return 0;
}
```
