#include <cassert>
#include <iostream>
#include <memory>
#include <cassert>
#include <iostream>

extern "C"
{
#include <luajit.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include <LuaBridge/LuaBridge.h>



using namespace std;
using namespace luabridge;
//g++ luajit.cpp -std=c++11 -I/usr/local/include/luajit-2.1 /usr/local/lib/libluajit-5.1.a -ldl -o a.out
auto make_luavm = []() {
    std::shared_ptr<lua_State> vm(
        luaL_newstate(), lua_close);
    assert(vm);

    luaL_openlibs(vm.get());
    return vm;
};

#define L vm.get() //

void case1()
{
    //MyLuaState L;
    auto vm = make_luavm();

    auto package = getGlobal(L, "package");

    string path = package["path"];
    string cpath = package["cpath"];

    cout << path << endl;
    cout << cpath << endl;
}

void case2()
{
    //MyLuaState L;
    auto vm = make_luavm();

    int status;

    status = luaL_dostring(L, "print('hello lua')");
    status = luaL_dofile(L, "./embedded.lua");
    status = luaL_dofile(L, "./shared.lua");
}
void case3()
{
    //MyLuaState L;
    auto vm = make_luavm();

    int status;
    string chunk = R"(
        function say(s)
            print(s)
        end
        function add(a, b)
            return a + b
        end
    )";

    status = luaL_dostring(L, chunk.c_str());
    assert(status == 0);

    auto f1 = getGlobal(L, "say");
    f1("say something");

    auto f2 = getGlobal(L, "add");
    auto v = f2(10, 20);
    assert(v == 30);
    //cout << v << endl;

    //L.dofile("./embedded.lua");
}

int main()
{
    case1();
    case2();
    case3();
    return 0;
}