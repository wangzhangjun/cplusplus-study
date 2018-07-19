# c++类模板实现在类内实现

```
#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age){
        this->name = name;
        this->age = age;
    }
    void show(){
        cout << "name:" << this->name << "age:" << this->age << endl;
    }
public:
    T1 name;
    T2 age;
};


int main() {

    Person<string ,int> p("zhang", 10);
    p.show();
    return 0;
}
```
