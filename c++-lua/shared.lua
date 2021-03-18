#!/usr/local/bin/luajit

local ffi = require "ffi"            -- 加载ffi库
local ffi_load = ffi.load            -- 函数别名
local ffi_cdef = ffi.cdef

ffi_cdef[[                           // 声明C接口
int num;
int my_add(int a, int b);
]]

local shared = ffi_load("./liblua_shared.so")    -- 加载动态库 

print(shared.num)                                -- 调用C接口
local x = shared.my_add(1, 2)                    -- 调用C接口