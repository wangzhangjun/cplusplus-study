#pragma once

#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

#include <cstdlib>
#include <cassert>
#include <atomic>
#include <thread>
#include "raii.h"
class RWLock {
#define WRITE_LOCK_STATUS -1
#define FREE_STATUS 0
private:
    static const  std::thread::id NULL_THEAD;
    const bool WRITE_FIRST;
    std::thread::id m_write_thread_id;
    std::atomic_int m_lockCount;
    std::atomic_uint m_writeWaitCount;
public:
    RWLock(const RWLock&) = delete;
    RWLock& operator=(const RWLock&) = delete;
    RWLock(bool writeFirst=false);
    virtual ~RWLock()=default;
    int readLock();
    int readUnlock();
    int writeLock();
    int writeUnlock();
    gyd::raii read_guard()const noexcept{
        return gyd::make_raii(*this,&RWLock::readUnlock,&RWLock::readLock);
    }
    gyd::raii write_guard()noexcept{
        return gyd::make_raii(*this,&RWLock::writeUnlock,&RWLock::writeLock);
    }
};
