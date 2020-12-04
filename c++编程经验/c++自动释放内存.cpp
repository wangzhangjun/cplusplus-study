#include <iostream>
#include <stdlib.h>

//g++ --std=c++11  c++自动释放内存.cpp
//利用局部对象出作用域的时候会默认的调用析构函数，提前把释放函数注册好，就会自动释放了。要注意需要在分配内存后，声明一个auto_destroyer的对象
template<typename T>
class auto_destroyer {
    typedef void (*Action)(T);
public:
    auto_destroyer(T res, Action action): res_(res), action_(action) {

    }
    ~auto_destroyer() {
        if (nullptr != action_) {
            action_(res_);
        }
    }
private:
    T res_;
    Action action_;
};

class Test {
public:
    void test() {
        std::cout << "test" <<std::endl;
    }
    ~Test(){
        std::cout << "test析构！" <<std::endl;
    }
private:
    int a ;
};

void freeTest(Test * test) {
    std::cout << "auto free memory" << std::endl;
    if(test!= nullptr){
        free(test);
        test = nullptr;
    }
}

int main(){
    Test *test = new Test();
    auto_destroyer<Test *> autoDeleteCmd(test, freeTest);
    return 0;
}
