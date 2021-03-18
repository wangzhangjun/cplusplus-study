#include <pybind11/pybind11.h>        // pybind11的头文件

//g++ 本文件名 -std=c++11 -shared -fPIC `python3 -m pybind11 --includes` -o pydemo`python3-config --extension-suffix`

namespace py = pybind11;               // 名字空间别名，简化代码

PYBIND11_MODULE(pydemo, m)             // 定义Python模块pydemo
{
  m.def("info",                        // 定义Python函数
    []()                              // 定义一个lambda表达式
    {
      py::print("c++ version =", __cplusplus);  // pybind11自己的打印函数
      py::print("gcc version =", __VERSION__);
      py::print("libstdc++   =", __GLIBCXX__);
    }
  );  

  m.def("add",                       // 定义Python函数
    [](int a, int b)                 // 有参数的lambda表达式
    {
      return a + b;
    }
  );  
}                     