//
// Created by zhjwang on 2021/3/18.
//

#ifndef BOOKSTORE_CPPLANG_H
#define BOOKSTORE_CPPLANG_H

#include <assert.h>
#include <atomic>
#include <thread>

//must be c++11 or later
#if __cplusplus < 201103
# error "c++ is to old"
#endif


//static_assert  静态断言，在编译阶段，编译器看到 static_assert 也会计算表达式的值，如果值是 false，就会报错，导致编译失败。
#if __cpp_static_assert >= 201411  //c++14
#    define STATIC_ASSERT(x) static_assert(x);
#else
#    define STATIC_ASSERT(x) static_assert(x, #x);
#endif

//namespace 的宏
#define BEGIN_NAMESPACE(x) namespace x{
#define END_NAMESPACE(X) }
#define USING_NAMESPACE(X) using namespace x

#endif //BOOKSTORE_CPPLANG_H
