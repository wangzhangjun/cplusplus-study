//
// Created by zhjwang on 2021/3/18.
//为了保证异常安全，在任何时候都不会死锁，使用RAII技术
//

#ifndef BOOKSTORE_SPINLOCKGUARD_H
#define BOOKSTORE_SPINLOCKGUARD_H
#include "cpplang.h"
#include "SpinLock.h"

BEGIN_NAMESPACE(cpp_study)

class SpinLockGuard final {
public:
    using this_type = SpinLockGuard;
    using spin_lock_type = SpinLock;
public:
    SpinLockGuard(const this_type&)() = delete;
    SpinLockGuard & operator=(const this_type &) = delete;
public:
    SpinLockGuard(spin_lock_type &lock) noexcept;
    ~SpinLockGuard() noexcept;
private:
    spin_lock_type &m_lock;
};

END_NAMESPACE(cpp_study)
#endif //BOOKSTORE_SPINLOCKGUARD_H
