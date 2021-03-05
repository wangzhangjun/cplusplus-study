//
// Created by zhjwang on 2021/3/5.
//

#include "shape.h"
#include <iostream>

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













