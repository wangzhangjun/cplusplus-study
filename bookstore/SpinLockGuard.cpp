//
// Created by zhjwang on 2021/3/18.
//

#include "SpinLockGuard.h"

cpp_study::SpinLockGuard::SpinLockGuard(spin_lock_type &lock) noexcept : m_lock(lock){
    m_lock.lock();
}

cpp_study::SpinLockGuard::~SpinLockGuard() noexcept {
    m_lock.unlock();
}
