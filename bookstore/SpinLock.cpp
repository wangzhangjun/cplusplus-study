//
// Created by zhjwang on 2021/3/18.
//

#include "SpinLock.h"

void cpp_study::SpinLock::lock() noexcept {
    for(;;){
        if(!m_lock.test_and_set()) {
            return ;  //TAS成功
        }
        std::this_thread::yield();  // TAS失败则让出线程
    }
}

void cpp_study::SpinLock::unlock() noexcept {
    m_lock.clear();
}

bool cpp_study::SpinLock::try_lock() noexcept {
    return !m_lock.test_and_set();  //原子变量set成功，返回true，否则返回false
}