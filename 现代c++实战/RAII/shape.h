//
// Created by zhjwang on 2021/3/5.
//

#ifndef 现代C_实战_SHAPE_H
#define 现代C_实战_SHAPE_H

enum  class shape_type {
    circle,
    triangle,
    rectangle,
};

class shape {
public:
    explicit shape();
    virtual void print();
    virtual ~shape();
};


#endif //现代C_实战_SHAPE_H
