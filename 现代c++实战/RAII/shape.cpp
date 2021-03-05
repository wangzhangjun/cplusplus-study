//
// Created by zhjwang on 2021/3/5.
//

#include "shape.h"
#include <iostream>

/*
知识点：
1. 如下例子，怎么保证new出来的shape的内存会被释放掉，统一的做法是：保存到一个变量，并且确保在析构函数中会去delete
2. 析构函数调用时机：
    1. 出{}这个的时候;
    2. delete的时候；
    3. delete指向对象的基类类型指针，而其基类虚构函数是虚函数时；
    4. 对象i是对象o的成员，o的析构函数被调用时，对象i的析构函数也被调用。
3. delete不用去判断是否为nullptr，因为delete实现的里面就会去判断
4. 这个案例类似一个简单的智能指针
*/

shape::shape() {
    std::cout << "shape" <<std::endl;
}

void shape::print() {
    std::cout << "I am shape" <<std::endl;
}

shape::~shape() {}

class circle : public shape {
public:
    circle() {
        std::cout << "I am circle" << std::endl;
    }
};

class triangle : public shape
{
public:
    triangle() {
        std::cout << "triangle" << std::endl;
    }
    virtual void print(){
        std::cout << "I am triangle" << std::endl;
    }
};

class rectangle : public shape
{
public:
    rectangle() {
        std::cout << "rectangle" << std::endl;
    }
    virtual void print(){
        std::cout << "I am rectangle" << std::endl;
    }
};

shape *create_shape(shape_type type) {
    switch (type) {
        case shape_type::circle:
            return new circle();
        case shape_type::triangle:
            return new triangle();
        case shape_type::rectangle:
            return new rectangle();
    }
}

class shape_wrapper{
public:
    explicit shape_wrapper(shape *ptr = nullptr) : ptr_(ptr) {}
    ~shape_wrapper(){
        delete ptr_;
    }
    shape *get() {
        return ptr_;
    }
private:
    shape *ptr_;
};

void foo()
{
    shape_wrapper ptr(create_shape(shape_type::circle));
    ptr.get()->print();
}

int main()
{
    // 第一种方式
    shape *sp = create_shape(shape_type::circle);
    sp->print();
    delete sp;
    // 第二种方式
    foo();
    return 0;
}













