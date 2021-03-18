
#include <luajit-2.1/luajit.h>

extern "C"
{ // 使用纯C语言的对外接口
    int num = 10;
    int my_add(int a, int b);
}

int my_add(int a, int b) // 一个简单的函数，供Lua调用
{
    return a + b;
}