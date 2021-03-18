#include <pybind11/pybind11.h>        // pybind11的头文件

//g++ pybind.cpp -std=c++11 -shared -fPIC `python3 -m pybind11 --includes` -o pydemo`python3-config --extension-suffix`

PYBIND11_MODULE(pydemo, m)            // 定义Python模块pydemo
{
  m.doc() = "pybind11 demo doc";      // 模块的说明文档
}                                     // Python模块定义结束
