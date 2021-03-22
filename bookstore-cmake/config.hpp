#ifndef _CONFIG_H__
#define _CONFIG_H__

#include "cpplang.hpp"
extern "C"
{
#include <luajit.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include <LuaBridge/LuaBridge.h>

BEGIN_NAMESPACE(cpp_study)

class config
{
public:
    using vm_type = std::shared_ptr<lua_State>;
    using value_type = luabridge::LuaRef;
    using string_type = std::string;
    using string_view_type = const std::string &;
    using regex_type = std::regex;
    using match_type = std::smatch;
public:
    Config() noexcept {
        assert(m_vm);
        lua_openlibs(m_vm.get());  //打开基本的lua库
    }
    ~Config() = default;
public:
    void load(string_view_type filename) const{
        
        auto status = luaL_dofile(m_vm.get(), filename.c_str());  //打开外部的lua脚本文件

        if (status != 0)
        {
            throw std::runtime_error("failed to parse config");
        }
    }
private:
    vm_type m_vm{luaL_newstate(), lua_close};
    const regex_type m_reg{R "(^(\w+)\.(\w+)$)"};
    mutable match_type m_what;
};

END_NAMESPACE(cpp_study)
#endif //!__BOOKSTORE-CMAKE_CONFIG_H__