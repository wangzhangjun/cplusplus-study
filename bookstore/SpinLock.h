//
// Created by zhjwang on 2021/3/18.
//

#ifndef BOOKSTORE_SPINLOCK_H
#define BOOKSTORE_SPINLOCK_H

#include "cpplang.h"

BEGIN_NAMESPACE(cpp_study)

class SpinLock final{  //final进制继承
public:
    using this_type = SpinLock;
    using atomic_type = std::atomic_flag;  //TAS(Test And Set) 操作，可以使用test_and_set去获取锁
public:
    SpinLock() = default;
    ~SpinLock() = default;

    SpinLock(const this_type &) = delete;
    SpinLock &operator=(const this_type&) = delete;

public:
    void lock() noexcept;
    bool try_lock() noexcept;
    void unlock() noexcept;
private:
    atomic_type  m_lock(false);
};

END_NAMESPACE(cpp_study)

#endif //BOOKSTORE_SPINLOCK_H
