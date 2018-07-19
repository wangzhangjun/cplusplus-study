# c++类模板实现在类的外部实现
写在类的外部指的是在该文件类的外面，声明和实现还是在同一个文件中。

```
#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void show();
public:
    T1 name;
    T2 age;
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
this->name = name;
this->age = age;
}

template <class T1, class T2>
void Person<T1, T2>::show(){
    cout << "name:" << this->name << "age:" << this->age << endl;
}

int main() {

    Person<string ,int> p("zhang", 10);
    p.show();
    return 0;
}
```
